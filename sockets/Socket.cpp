#include "Socket.h"
#include <exception>
#include "API/events/ClientConnectedEvent.h"
#include <unistd.h>
#include <sstream>
#include <error.h>
#include "encrypt/Encrypt.h"

Socket::Socket()
{
    symKey = 0;
    afterInit = false;
    addrLen = sizeof(clientAddress);
    socketDescriptor=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socketDescriptor==-1) throw std::runtime_error("Nie można utworzyc gniazda.\n");
}

void Socket::setPort(int port)
{
    this->port=port;
}

void Socket::bind()
{
    struct sockaddr_in name;
    name.sin_family = AF_INET;
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    name.sin_port = htons((short)port);

    if(::bind(socketDescriptor, (struct sockaddr*)&name, sizeof(name))!=0)
        throw std::runtime_error("Bind() nie powiodl sie.\n");
}

void Socket::listen()
{
    if(::listen(socketDescriptor, 128)!=0)
        throw std::runtime_error("Blad \"stowarzyszenia\" gniazda. (listen()).\n");
    isServer=true;
}

void Socket::connect(std::string addr, int port)
{
    struct sockaddr_in name;
    name.sin_family = AF_INET;
    name.sin_addr.s_addr = inet_addr(addr.c_str());
    name.sin_port = htons((short)port);

    if(::connect(socketDescriptor,(struct sockaddr*)&name, sizeof(name))!=0)
        throw std::runtime_error("Nie mozna zestawic polaczenia z dana maszyna.\n");
    isServer=false;

    std::pair<std::pair<int,int>,std::pair<int,int>> keys = Encrypt::getAsymKeys();
    int buf[2];
    buf[0] = keys.first.first;
    buf[1] = keys.first.second;
    int bufRecv[1] = { 0 };
    this->write((char*)buf, 8);
    this->read((char*)bufRecv, 4);
    symKey = (char)Encrypt::asymCrypt(bufRecv[0], keys.second.first, keys.second.second);
    std::cout<<"klucz symetryczny(klient):  "<<symKey<<std::endl;
    afterInit = true;
}

void Socket::accept(EventListener evL)
{
    //trzeba bedzie w watku serwera zamykac nowy socket, a w watku obslugi polaczenia socket serwera
    clientSocketDescriptor = ::accept(socketDescriptor, &clientAddress, &addrLen);
    if(clientSocketDescriptor == -1) throw std::runtime_error("accept() error.\n");
    ClientConnectedEvent *event = new ClientConnectedEvent("connected");

    int keyBuf[2];
    this->read((char*)keyBuf, 8);
    do{
        symKey = rand() % 256;
    }while(!symKey);
    std::cout<<"klucz symetryczny(serwer):  "<<symKey<<std::endl;
    int sendKey[1] = { Encrypt::asymCrypt((int)symKey, keyBuf[0], keyBuf[1]) };
    this->write((char*)sendKey, 4);
    afterInit = true;
    evL(event);     //w tym evencie bedzie funkcja do odpalenia nowego watku?
}

void Socket::close()
{
    if(isServer) close(clientSocketDescriptor);
    if(::close(socketDescriptor)!=0)
        throw std::runtime_error("Blad podczas zamykania polaczenia.\n");
}

void Socket::close(int sockFd)
{
    if(::close(sockFd)!=0)
        throw std::runtime_error("Blad podczas zamykania polaczenia.\n");
}

int Socket::write(char * buf, int nbytes)
{
    if(afterInit)
    {
        Encrypt::symCrypt(buf, nbytes, symKey);
    }
    int count;
    if(isServer) count = ::send(clientSocketDescriptor, (const void *)buf, (size_t)nbytes, 0);
    else count = ::send(socketDescriptor, (const void *)buf, (size_t)nbytes, 0);
    if(count==-1) {
        std::stringstream ss;
        ss << "Blad podczas wysylania danych.\n" ;
        ss << "Numer bledu: " << errno << "\n";
        throw std::runtime_error(ss.str());
    }
    else return count;
}

int Socket::read(char * buf, int nbytes)
{
    int count;
    if(isServer) count = ::recv(clientSocketDescriptor, (void*)buf, (size_t)nbytes, 0);
    else count = ::recv(socketDescriptor, (void*)buf, (size_t)nbytes, 0);
    if(count==-1) throw std::runtime_error("Blad podczas czytania danych.\n");
    else {
        if(afterInit){
            Encrypt::symCrypt(buf, count, symKey);
        }
        return count;
    }
}

