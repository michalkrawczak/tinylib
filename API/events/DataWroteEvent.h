#ifndef DATAWROTEEVENT_H
#define DATAWROTEEVENT_H

#include "SuccessEvent.h"

class DataWroteEvent : public SuccessEvent
{
public:
    DataWroteEvent(std::string);
    virtual ~DataWroteEvent(){}
};

#endif // DATAWROTEEVENT_H
