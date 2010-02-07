/*
 * Jeff Shoulders and Robert Butler
 * hx86 working group
 *
 *hx86 Messaging classes
 */

#include "../../poleaxe.h"

//Message constructor
 message::message()
 {
     handle = 0;
     msgType = MSG_NO_MESSAGE;
     param1 = 0;
     param2 = 0;
     data = NULL;
 }


 //Message constructor
 message::message(HANDLE _handle, DWORD _msgType, DWORD _param1, DWORD _param2, void *_data)
 {
 /*                            char *buf = (char *)malloc(sizeof(char *) * 20);
                        sprintf(buf, "Creating Message, Mouse X: %d, Mouse Y: %d", (int)_param1, (int)_param2);
                        HXLOG(buf);*/
     handle = _handle;
     msgType = _msgType;
     param1 = _param1;
     param2 = _param2;
     data = _data;
 }


//Message deconstructor
message::~message()
{
}


//returns the handle from the message
HANDLE message::Handle()
{
    return handle;
}


void message::Handle(HANDLE _handle)
{
    handle = _handle;
    return;
}


//returns the message type
DWORD message::MessageType()
{
    return msgType;
}


DWORD message::Param1()
{
    return param1;
}


DWORD message::Param2()
{
    return param2;
}


//Used to alter the Paramters after object creation
void message::Param1(DWORD Param1)
{
    this->param1 = Param1;
}


void message::Param2(DWORD Param2)
{
    this->param2 = Param2;
}


//returns the Data paramter from the message
void *message::Data()
{
    return data;
}


void message::Data(void *data)
{
    this->data = data;
}
