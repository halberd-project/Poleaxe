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


keyboard::keyboard()
{
    install_keyboard();
    LogMessage("Keyboard subsystem has been initialized.");
    keyboard_callback = KeyboardCallback;
	this->caps = CapsLock();
	this->scroll = ScrollLock();
	this->num = NumLock();
}


keyboard::~keyboard()
{
	remove_keyboard();
	LogMessage("Keboard subsystem has been uninitialized.");
}


void EnableUnicode()
{
}


void DisableUnicode()
{
}


bool keyboard::CapsLock()
{
    return this->caps;
}


bool keyboard::ScrollLock()
{
    return this->scroll;
}


bool keyboard::NumLock()
{
    return this->num;
}

