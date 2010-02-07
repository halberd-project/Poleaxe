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
#include <stdarg.h>

#define __POL_DEBUG_MODE__


//Prints a time stamp
void TimeStamp()
{
    #ifdef __POL_DEBUG_MODE__
    char timestamp[100];
    time_t mytime;
    struct tm *mytm;

    mytime=time(NULL);
    mytm=localtime(&mytime);
    strftime(timestamp,sizeof timestamp,"%a, %d %b %Y %H:%M:%S",mytm);
    printf("%s",timestamp);
    #endif
}


//LogMessage takes a variable number of arguments, prints a timestamp
//and then displays the message on the screen, and or a log file.
void LogMessage(char *fmt, ...)
{
    #ifdef __POL_DEBUG_MODE__
	va_list args;
	char buffer[256];

	TimeStamp();
	va_start(args, fmt);
	vsprintf(buffer, fmt, args);
	printf(":  %s\n", buffer);
	va_end(args);
	return;
	#endif
}



//LogError takes a variable number of arguments, prints a timestamp
//and then displays the message on the screen, and or a log file.
void LogError(char *fmt, ...)
{
    #ifdef __POL_DEBUG_MODE__
	va_list args;
	char buffer[256];

	TimeStamp();
	va_start(args, fmt);
	vsprintf(buffer, fmt, args);
	fprintf(stderr, ":  %s\n", buffer);
	va_end(args);
	return;
	#endif
}
