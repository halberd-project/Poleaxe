/*
 * Jeff Shoulders and Robert Butler
 * hx86 working group
 *
 */

#ifndef __POL_FRAME__
#define __POL_FRAME__


#include "../../poleaxe.h"


class frame : public object
{
    public:
       frame();
       ~frame();

       // Allows all derivitive object to recieve messages
       virtual void Recv(Message m);
};

#endif
