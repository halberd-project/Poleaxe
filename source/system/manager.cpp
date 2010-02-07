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


Manager PoleaxeManager;


manager::manager()
{
    base_handle = (HANDLE)0;
    number_of_windows = 0;
    msg_queue = MessageQueue(new messagequeue());
}


manager::~manager()
{
}


Window manager::FocusWindow()
{
    return focus_window;
}


HANDLE manager::FocusWindowHandle()
{
    return focus_window->Handle();
}


Window manager::FindWindowByHandle(HANDLE win_handle)
{
    return window_list;
}


WORD manager::NumberOfWindows()
{
    return number_of_windows;
}


void manager::AddWindow(Window w)
{
    window_list = w;
    string str_title = w->Title();
    char *_title = (char *)str_title.c_str();
    LogMessage("Added new Window: %s.", (char *)_title);
    return;
}


void manager::RemoveWindow(Window w)
{
    return;
}


HANDLE manager::NextAvailableHandle()
{
    base_handle++;
    return (base_handle - 1);
}


void manager::Enqueue(Message _data)
{
    msg_queue->Enqueue(_data);
}


void manager::EnqueueGlobalMessage(Message _data)
{
    if(_data->Handle() != -1)
        _data->Handle(-1);      //ensure that the handle is -1 to denota a global message

    msg_queue->Enqueue(_data);
}


void manager::SystemKeyHandler(Message m)
{
    if(m->Param2() == KEY_ESC)
        QueueMessage(MSG_EXIT);

    if(focus_window)
    {
        //build a new proper message for the focus window.
        Message msg = Message(new message(focus_window->Handle(),
                                          KEY_DOWN,
                                          m->Param1(),
                                          m->Param2(),
                                          m->Data()));
        focus_window->Enqueue(msg);
    }

    return;
}


void manager::SystemMouseHandler(Message m)
{
    if(focus_window)
        focus_window->Enqueue(m);

    return;
}


void manager::MessageLoop()
{
    Message m = Message(new message());
    bool running = true;

    while(running)
    {
        if(!msg_queue->Empty())
        {
            m = msg_queue->Dequeue();
            if((m->Handle() != 0) || (m->Handle() != -1))
            {
                //find the window with the handle and pass it on.
            }
            switch(m->MessageType())
            {
                case MSG_SYSTEM_SHUTDOWN:
                {
                    break;
                }
                case MSG_STARTUP:
                {
                    break;
                }
                case MSG_EXIT:
                {
                    running = false;
                    LogMessage("Exit Message has been received.");
                    LogMessage("Sending message to all windows and threads.");
                    QueueGlobalMessage(m);
                    break;
                }
                case MSG_GFX_SCREEN_RES_CHANGED:
                {
                    LogMessage("Screen resolution has been changed.");
                    break;
                }
                case MSG_MOUSE_STATE_CHANGE:
                {
                    SystemMouseHandler(m);
                    break;
                }
                case MSG_KEYBOARD_STATE_CHANGE:
                {
                    SystemKeyHandler(m);
                    break;
                }
                case MSG_NO_MESSAGE:
                default:
                {
                    break;
                }
            }
        }
    }
}
