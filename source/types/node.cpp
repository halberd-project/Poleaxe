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


#include "../../poleaxe.h"


node::node()
{
    data = Message(new message());
    prev = NULL;
    next = NULL;
}


node::node(Message _data)
{
    data = _data;
    prev =  NULL;
    next =  NULL;
}


node::~node()
{
}


Message node::Data()
{
    return data;
}


void node::Data(Message _data)
{
    data = _data;
}


node *node::Next()
{
    return next;
}


node *node::Previous()
{
    return prev;
}


void node::Next(node *_next)
{
    next = _next;
}


void node::Previous(node *_prev)
{
    prev = _prev;
}
