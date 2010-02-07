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


namespace Alleg
{
    void Init()
    {
        if(allegro_init() != 0)
        {
            LogError("Error initializing Allegro.\n");
            LogError("Allegro returned this error message: %s", allegro_error);
            return;
        }

        LogMessage("Allegro has been initialized.");
    }
}
