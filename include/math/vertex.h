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


#ifndef _VERTEX_H_
#define _VERTEX_H_

#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
//#include <gl\glaux.h>
#include <il\il.h>
#include <il\ilu.h>
#include <il\ilut.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#pragma comment(lib, "devil.lib")
#pragma comment(lib, "ilu.lib")
#pragma comment(lib, "ilut.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
//#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "winmm.lib")





inline WORD color(BYTE r, BYTE g, BYTE b, BYTE a)
{
	WORD ret;
	ret = ((0xff000000 & (r << 16)) | (0x00ff0000 & (g << 12)) | (0x0000ff00 & (b << 8)) | (0x000000ff & a));
	/*ret = ret + (0xff000000 & (r << 16));
	ret = ret + (0x00ff0000 & (g << 12));
	ret = ret + (0x0000ff00 & (b << 8));
	ret = ret + (0x000000ff & a);/**/
	return ret;
}

#endif
