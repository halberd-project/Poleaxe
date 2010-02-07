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

#ifndef __OBJECT__
#define __OBJECT__


#include "../../poleaxe.h"


class object
{
	protected:
        //x and y are coordinates on the screen, z is the depth in relation to other windows and objects
		WORD x, y, z;
		//w and h are width and height of the object
		WORD w, h;
		//handle to the object, much like in Windows.
		HANDLE handle;

    public:
       object();
       virtual ~object();

       void Handle(HANDLE _h);
       HANDLE Handle();

		//messages and such
		virtual void OnMouseClick(WORD _x, WORD _y, BYTE buttons, WORD flags);
		virtual void OnMouseEnter(WORD _x, WORD _y, BYTE buttons, WORD flags);
		virtual void OnMouseLeave(WORD _x, WORD _y, BYTE buttons, WORD flags);
		virtual void OnMouseMove(WORD _x, WORD _y, BYTE buttons, WORD flags);
		virtual void OnResize(WORD _x, WORD _y, WORD _w, WORD _h, WORD flags);
		virtual void OnCreate();
		virtual void OnClose();
		virtual void OnExit();
		virtual void OnDraw();
		virtual void Draw();
		virtual void OnKeyDown(WORD keys, WORD flags);
		virtual void OnKeyUp(WORD keys, WORD flags);
		virtual void ReceiveMessage(Message m);


		//general information, x, y, etc...
		void X(WORD _x);
		WORD X();
		void Y(WORD _y);
		WORD Y();
		//Z is the depth of the window in relationship to other windows.
		void Z(WORD _z);
		WORD Z();

		void Width(WORD _w);
		WORD Width();
		void Height(WORD _h);
		WORD Height();
};


#endif
