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


#ifndef __POL_MESSAGEQUEUE__
#define __POL_MESSAGEQUEUE__

#include "../../poleaxe.h"


class messagequeue : public list
{
    protected:

    public:
        messagequeue();                             //constructor
        ~messagequeue();                            //destructor
        Message Dequeue();                          //removes the top most element on the queue
        void Enqueue(Message _data);                //enqueues the data onto the queue
        Message Examine();                          //retrieves the top most element, without removing it unlike Dequeue
};


#endif          //_POL_QUEUE
