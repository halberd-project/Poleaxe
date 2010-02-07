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


#ifndef __POL_TYPES__
#define __POL_TYPES__


#include "../../poleaxe.h"


typedef struct Vertex
{
	float x, y, z;
	WORD c;
} VERTEX;


typedef struct Point
{
    int x, y;
} point, POINT;


typedef struct _frect
{
    float x1, y1;
    float x2, y2;
} FRect, FRECT;


typedef struct _irect
{
    int x1, y1;
    int x2, y2;
} Rect, RECT;


typedef struct Light
{
	float x, y, z;
	float r, g, b, a;
	bool type;
	int id;
} LIGHT;


typedef struct tri
{
		float x, y, z;
} tri;


#endif			//__POL_TYPES__
