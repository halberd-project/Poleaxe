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


#ifndef __POL_MOUSE__
#define __POL_MOUSE__


#include "../../poleaxe.h"


class mouse : public object
{
 	protected:
 		WORD	x, y;
 		WORD	buttons;


 	public:
 													mouse();
 													~mouse();
 		WORD										X();
 		WORD										Y();
 		WORD										Buttons();
 		void 										Scare();
 		void										Unscare();
 		//displays the mouse on the screen
 		void										Show();
 		//displays the mouse on the supplied surface
 		void										Show(Surface s);
 		//changes the mouse bitmap to the supplied bitmap
 		//sets the cursor to the allegro supplies cursor from this table.
 		/* 		MOUSE_CURSOR_ALLEGRO
				MOUSE_CURSOR_ARROW
				MOUSE_CURSOR_BUSY
				MOUSE_CURSOR_QUESTION
				MOUSE_CURSOR_EDIT		*/
 		void										Cursor(int cursor, Surface s);

 		//restricts the movement of the mouse to a small rect on the screen
 		//there are two functions one that takes the coordinates directly, and another
 		//that uses a rect argument.
 		void										Range(WORD _x, WORD _y, WORD _w, WORD _h);
 		void										Range(RECT _r);

 		//sets the mouse position
 		void										Position(WORD _x, WORD _y);
 		void										Position(POINT _p);
 		void										PositionWheel(WORD _z);				//sets the mouse wheel position
 		void										Speed(WORD _x_speed, WORD _y_speed);	//mouse speed...
 		void										Speed(WORD _speed);

 		//mouse mickeys. heh.
 		POINT										Mickeys();
 		void										Mickeys(int *_x, int *_y);

 		//mouse callback function
		friend void									MouseCallback(int f);

};

//Mouse SystemMouse;
extern inline void MouseCallback(int f)
{
    QueueMessage(Message(new message(0, MSG_MOUSE_STATE_CHANGE, MAKEDWORD(mouse_x, mouse_y), (DWORD)mouse_b, null)));
}END_OF_FUNCTION(MouseCallback)


#endif			//__POL_MOUSE__
