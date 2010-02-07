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


mouse::mouse()
{
    install_mouse();
    LogMessage("Mouse subsystem has been initialized.");
    mouse_callback = MouseCallback;      //set the mouse callback function
    LOCK_FUNCTION(Callback);
    LOCK_VARIABLE(x);
    LOCK_VARIABLE(y);
    LOCK_VARIABLE(buttons);
}


mouse::~mouse()
{
	remove_mouse();
	LogMessage("Mouse subsystem has been uninitialized.");
}


WORD mouse::X()
{
    return x;
}


WORD mouse::Y()
{
    return y;
}


WORD mouse::Buttons()
{
    return buttons;
}


void mouse::Scare()
{
    scare_mouse();
}


void mouse::Unscare()
{
    unscare_mouse();
}


void mouse::Show()
{
    show_mouse(::screen);
}


void mouse::Show(Surface s)
{
    show_mouse(s->AllegroBitmap());
}


void mouse::Cursor(int cursor, Surface s)
{
    set_mouse_cursor_bitmap(cursor, s->AllegroBitmap());
}


void mouse::Range(WORD _x, WORD _y, WORD _w, WORD _h)
{
    set_mouse_range(_x, _y, _w, _h);
}


void mouse::Range(RECT _r)
{
    set_mouse_range(_r.x1, _r.y1, _r.x2, _r.y2);
}


void mouse::Position(WORD _x, WORD _y)
{
    position_mouse(_x, _y);
}

void mouse::Position(POINT _p)
{
    position_mouse(_p.x, _p.y);
}


void mouse::PositionWheel(WORD _z)
{
    position_mouse_z(_z);
}


void mouse::Speed(WORD _x_speed, WORD _y_speed)
{
    set_mouse_speed(_x_speed, _y_speed);
}


void mouse::Speed(WORD _speed)
{
    set_mouse_speed(_speed, _speed);
}


POINT mouse::Mickeys()
{
    int x, y;
    POINT p;

    get_mouse_mickeys(&x, &y);
    p.x = x;
    p.y = y;

    return p;
}


void mouse::Mickeys(int *_x, int *_y)
{
    get_mouse_mickeys(_x, _y);
}
