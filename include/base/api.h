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


#ifndef __POL_GENERAL_API__
#define __POL_GENERAL_API__

#include "../../poleaxe.h"


/*
 *  Functions for handling messages.
 */

void                QueueMessage(Message m);                   //puts the message in a queue and returns
void                QueueMessage(DWORD m);
void                QueueMessage(DWORD m, DWORD p1, DWORD p2);
void                QueueGlobalMessage(Message m);                   //puts the message in a queue and returns
void                QueueGlobalMessage(DWORD m);
void                QueueGlobalMessage(DWORD m, DWORD p1, DWORD p2);


/*
 *  Functions for creating and handling Windows and Dialog boxes.
 */

//Similiar to the Windows function
HRESULT MessageBox(const string& msgTitle, const string& msgText, WORD msgIcon);
//Creates and returns a Window object
Window CreateWindow(const string& Title, WORD X, WORD Y, WORD H, WORD W, DWORD Flags);


#endif          //__POL_GENERAL_API__
