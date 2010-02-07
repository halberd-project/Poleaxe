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


#ifndef __POL_KEYBOARD__
#define __POL_KEYBOARD__


#include "../../poleaxe.h"


#define KEY_ON			true
#define KEY_OFF			false


/*
	Allegro shift key defines...

	      KB_SHIFT_FLAG
	      KB_CTRL_FLAG
	      KB_ALT_FLAG
	      KB_LWIN_FLAG
	      KB_RWIN_FLAG
	      KB_MENU_FLAG
	      KB_COMMAND_FLAG
	      KB_SCROLOCK_FLAG
	      KB_NUMLOCK_FLAG
	      KB_CAPSLOCK_FLAG
	      KB_INALTSEQ_FLAG
	      KB_ACCENT1_FLAG
	      KB_ACCENT2_FLAG
	      KB_ACCENT3_FLAG
     	  KB_ACCENT4_FLAG
*/


class keyboard : public object
{
	protected:
		bool										caps, scroll, num;


	public:
													keyboard();
													~keyboard();
        void                                        EnableUnicode();
        void                                        DisableUnicode();
		bool										Key(BYTE _key);
		bool										Shifts();
		bool										KeyPressed();
		WORD										ReadKey();
		WORD										UnicodeReadKey();
		WORD										Poll();
		void										CapsLockLED(BYTE _switch);
		void										ScrollLockLED(BYTE _switch);
		void										NumLockLED(BYTE _switch);

		//individual state key functions
		bool										Shift();
		bool										Ctrl();
		bool										Alt();
		bool										LWin();
		bool										RWin();
		bool										Menu();
		bool										Command();
		bool										ScrollLock();
		bool										NumLock();
		bool										CapsLock();
		bool										InAltSeq();


		//callbacks
		friend int								    KeyboardCallback(int key);
		//void										UnicodeCallback(void (*mouse_callback));
};


extern inline int KeyboardCallback(int key)
{
    //Param1 is the ASCII value
    //Param2 is the scancode.
    QueueMessage(Message(new message(0, MSG_KEYBOARD_STATE_CHANGE, (DWORD)key, (DWORD)(key >> 8), null)));
    return key;
}END_OF_FUNCTION(KeyboardCallback)


#endif			//__POL_KEYBOARD__
