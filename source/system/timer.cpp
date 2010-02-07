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


timer::timer()
{
    install_timer();
    LogMessage("Timer subsystem initialized.");
}


timer::~timer()
{
    LogMessage("Timer subsystem uninitialized.");
}
