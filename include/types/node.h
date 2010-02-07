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


#ifndef __POL_NODE__
#define __POL_NODE__


#include "../../poleaxe.h"


class node
{
    protected:
        Message data;
        node *prev, *next;

    public:
        node();
        node(Message _data);
        ~node();
        Message Data();
        void Data(Message _data);
        node *Next();
        node *Previous();
        void Next(node *_next);
        void Previous(node *_prev);
};


#endif      //__POL_LIST__
