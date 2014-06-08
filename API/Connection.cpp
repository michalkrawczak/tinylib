#include "Connection.h"

Connection::Connection(Socket socket)
{
    writing_thread.run();
    reading_thread.run();
    listener_call_thread.run();
    state = ConnectionState::CREATED;
}

AsyncOperation* Connection::writeAsync(char *data, int dataSize, EventListener success, EventListener failure)
{
    WritingAction action(socket, data, dataSize, success, failure, listener_call_thread);
    writing_thread.add(action);
    return new AsyncOperation(action);
}

AsyncOperation* Connection::readAsync(char *data, int dataSize, EventListener success, EventListener failure)
{
    ReadingAction action(socket, data, dataSize, success, failure, listener_call_thread);
    reading_thread.add(action);
    return new AsyncOperation(action);
}
