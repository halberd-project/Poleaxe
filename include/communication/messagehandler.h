/*
 *
 *		The Poleaxe Graphics and Windowing system.
 *
 * Jeff Shoulders and Robert Butler
 * hx86 working group
 * loliniel@gmail.com
 * lighth7015@gmail.com
 *
 *	(c) 2010
 *
 */


#ifndef __POL_MESSAGE_HANDLER__
#define __POL_MESSAGE_HANDLER__

#include "../../poleaxe.h"


class messagehandler : public object
{
    protected:
        MessageQueue mq;

    public:
        messagehandler();
        ~messagehandler();
        int NumberOfMessage();
};


#endif
