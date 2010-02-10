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

//altered on January 27th, 2010 at 02:22


#ifndef __POL_DEBUG__
#define __POL_DEBUG__


#include "../../poleaxe.h"


//Utility functions
//I will slightly redo these to support variable arguments soon
void TimeStamp();
void LogMessage(const char *fmt, ...);
void LogError(const char *fmt, ...);


//for compatibility
#define HXERROR	LogError
#define HXLOG	LogMessage



//depricated, use above functions
//Log and Error macros
//#define HXERROR(string)     TimeStamp(); printf(":\t%s\n", string);
//#define HXLOG(string)       TimeStamp(); printf(":\t%s\n", string);



#endif              //__HXUTILITY__
