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


list::list()
{
    base = null;
    i = null;
    end = null;
    num_nodes = 0;
}


list::~list()
{
    if(base)
        delete base;
    if(i)
        delete i;
    if(end)
        delete end;
}


bool list::AddNode(Node *_node)
{
    return false;
}


bool list::DeleteNode()
{
    return false;
}


int list::NumberOfNodes()
{
    return num_nodes;
}


node *list::Iterator()
{
    return i;
}


node *list::Base()
{
    return base;
}


node *list::End()
{
    return end;
}


void list::Clear()
{
    if(base)
        delete base;
    if(i)
        delete i;
    if(end)
        delete end;
    num_nodes = 0;
}


bool list::Empty()
{
    if(base == null)
        return true;

    return false;
}
