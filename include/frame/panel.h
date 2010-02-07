/*
 * Jeff Shoulders and Robert Butler
 * hx86 working group
 *
 */

#ifndef __POL_PANEL__
#define __POL_PANEL__


#include "../../poleaxe.h"


class panel : public object
{
    public:
       panel();
       ~panel();

       // Allows all derivitive object to recieve messages
       virtual void Recv(Message m);
};

#endif

