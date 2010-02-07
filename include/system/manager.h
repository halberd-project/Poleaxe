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


#ifndef __POL_MANAGER__
#define __POL_MANAGER__


#include "../../poleaxe.h"


/*
 *      This class is an object that describes a window manager.  It will handle various inputs and send
 * them to the correct recipients.  It will handle telling objects when to draw and so on.
 *
 */


class manager : public object
{
    protected:
        HANDLE                                                  base_handle;
        Window                                                  window_list;
        WORD                                                    number_of_windows;
        Window                                                  focus_window;
        MessageQueue                                            msg_queue;

    public:
                                                                manager();
                                                                ~manager();

        Window                                                  FocusWindow();
        HANDLE                                                  FocusWindowHandle();
        Window                                                  FindWindowByHandle(HANDLE win_handle);
        WORD                                                    NumberOfWindows();
        void                                                    AddWindow(Window w);
        void                                                    RemoveWindow(Window w);
        HANDLE                                                  NextAvailableHandle();
        void                                                    SystemKeyHandler(Message m);
        void                                                    SystemMouseHandler(Message m);
        void                                                    MessageLoop();
        void                                                    Enqueue(Message _data);
        void                                                    EnqueueGlobalMessage(Message _data);
};


#endif              //__POL_MANAGER__
