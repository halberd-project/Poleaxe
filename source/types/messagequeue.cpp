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


messagequeue::messagequeue()
{
    LogMessage("Messaging subsystem has been initialized.");
}


messagequeue::~messagequeue()
{
    LogMessage("Messaging subsystem has been uninitialized.");
}


Message messagequeue::Dequeue()
{
    Message ret_data = Message(new message());

    if(base == null)
        return ret_data;
    else if(base == end)
    {
        ret_data = base->Data();
        base = null;
        end = null;
        num_nodes--;
        return ret_data;
    }
    else
    {
        ret_data = end->Data();
        if(base == end)
            end = base;
        else
        {
            end = end->Previous();
            end->Next(null);
        }
        num_nodes--;
        return ret_data;
    }
    return ret_data;
}


void messagequeue::Enqueue(Message _data)
{
    num_nodes++;

    if(base == null)
    {
        base = new node(_data);
        end = base;
        return;
    }
    else if(base == end)
    {
        base->Next(new node(_data));
        end = base->Next();
        end->Previous(base);
        return;
    }
    else
    {
        node *_prev = end;
        end->Next(new node(_data));
        end = end->Next();
        end->Previous(_prev);
        return;
    }

    return;
}


//looks at the last message in the queue and returns it without removing it from the queue
//if their is no message in the queue, then it will return a blank message.
Message messagequeue::Examine()
{
    Message ret_data = Message(new message());

    if(base == null)
        return ret_data;
    else
    {
        ret_data = end->Data();
        return ret_data;
    }
    return ret_data;
}


void QueueMessage(Message m)
{
    PoleaxeManager->Enqueue(m);
    return;
}


void QueueMessage(DWORD m)
{
    //post a new message with no additional parameters
    PoleaxeManager->Enqueue(Message(new message(0, m, 0, 0, NULL)));
    return;
}


void QueueMessage(DWORD m, DWORD p1, DWORD p2)
{
    PoleaxeManager->Enqueue(Message(new message(0, m, p1, p2, NULL)));
    return;
}


void QueueGlobalMessage(Message m)
{
    PoleaxeManager->EnqueueGlobalMessage(m);
    return;
}


void QueueGlobalMessage(DWORD m)
{
    PoleaxeManager->EnqueueGlobalMessage(Message(new message(0, m, 0, 0, NULL)));
    return;
}


void QueueGlobalMessage(DWORD m, DWORD p1, DWORD p2)
{
    PoleaxeManager->EnqueueGlobalMessage(Message(new message(0, m, p1, p2, NULL)));
    return;
}
