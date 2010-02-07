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


object::object()
{
	return;
}


object::~object()
{
	return;
}


void object::Handle(HANDLE _h)
{
	this->h = _h;
	return;
}


HANDLE object::Handle()
{
	return this->h;
}


void object::X(WORD _x)
{
	this->x = _x;
}


WORD object::X()
{
	return this->x;
}


void object::Y(WORD _y)
{
	this->y = _y;
}


WORD object::Y()
{
	return this->y;
}


void object::Z(WORD _z)
{
	this->z = _z;
}


WORD object::Z()
{
	return this->z;
}


void object::Width(WORD _w)
{
	this->w = _w;
}


WORD object::Width()
{
	return this->w;
}


void object::Height(WORD _h)
{
	this->h = _h;
}


WORD object::Height()
{
	return this->h;
}


void object::OnMouseClick(WORD _x, WORD _y, BYTE buttons, WORD flags)
{
}


void object::OnMouseEnter(WORD _x, WORD _y, BYTE buttons, WORD flags)
{
}


void object::OnMouseLeave(WORD _x, WORD _y, BYTE buttons, WORD flags)
{
}


void object::OnMouseMove(WORD _x, WORD _y, BYTE buttons, WORD flags)
{
}


void object::OnResize(WORD _x, WORD _y, WORD _w, WORD _h, WORD flags)
{
}


void object::OnCreate()
{
}


void object::OnClose()
{
}


void object::OnExit()
{
}


void object::OnDraw()
{
}


void object::Draw()
{
}


void object::OnKeyDown(WORD keys, WORD flags)
{
}


void object::OnKeyUp(WORD keys, WORD flags)
{
}


void object::ReceiveMessage(Message m)
{
	if(m == NULL)
		return;

	switch(m->MessageType())
	{
		case MSG_STARTUP:
		{
			LogMessage("Received a startup message.");
			break;
		}
		case MSG_EXIT:
		{
			LogMessage("Received an exit message.");
			break;
		}
		default:
		{
			break;
		}
	}

	return;
}
