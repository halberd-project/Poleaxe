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


 #ifndef __POL_MESSAGE__
 #define __POL_MESSAGE__


//system events
#define MSG_STARTUP								    0
#define MSG_EXIT								    1
#define MSG_SYSTEM_SHUTDOWN                         2
#define MSG_NO_MESSAGE                              3
#define MSG_SHOW_DESKTOP                            4
#define MSG_CHANGE_DESKTOP                          5


// Mouse Event types
#define MSG_MOUSE_BUTTON_DOWN                       100
#define MSG_MOUSE_BUTTON_UP                         102
#define MSG_MOUSE_MOVE                              103
#define MSG_MOUSE_MOVE_Z                            104
#define MSG_MOUSE_STATE_CHANGE                      105
#define MSG_MOUSE_BUTTON_CHANGE                     106


//Keyboard Event types
#define MSG_KEYBOARD_STATE_CHANGE                   200
#define MSG_KEY_UP                                  201
#define MSG_KEY_DOWN                                202
#define MSG_SYSKEY_UP                               203
#define MSG_SYSKEY_DOWN                             204


//networking / socket events
//todo later


//graphics events
#define MSG_GFX_SCREEN_RES_CHANGED                  400


//Window events
#define MSG_WIN_CREATE                              1001
#define MSG_WIN_DESTROY                             1002
#define MSG_WIN_CLOSE                               1003
#define MSG_WIN_RESIZE                              1004
#define MSG_WIN_MINIMIZE                            1005
#define MSG_WIN_MAXIMIZE                            1006
#define MSG_WIN_MOVE                                1007
#define MSG_WIN_POSITION_CHANGED                    1008
#define MSG_WIN_GAIN_FOCUS                          1009
#define MSG_WIN_LOST_FOCUS                          1010
#define MSG_WIN_MOVING                              1011
#define MSG_WIN_ENABLE                              1012
#define MSG_WIN_DISABLE                             1013


class message : public object
{
    protected:
        HANDLE handle;
        DWORD msgType;
        DWORD param1, param2;
        void *data;

    public:
        message();
        message(HANDLE _handle, DWORD _msgType, DWORD _param1, DWORD _param2, void *_data);
        ~message();

        HANDLE Handle();
        void Handle(HANDLE _handle);
        DWORD MessageType();
        DWORD Param1();
        DWORD Param2();
        void Param1(DWORD Param1);
        void Param2(DWORD Param2);
        void *Data();
        void Data(void *Data);
};


#endif          //__POL_MESSAGE__
