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


#ifndef __POL_MATH_MISC__
#define __POL_MATH_MISC__


#include "../../poleaxe.h"


inline Vector CalcFaceNormal(Vector *p0, Vector *p1, Vector *p2)
{
	Vector x, y, z;
	x = *p0;
	y = *p1;
	z = *p2;
	Vector v0 = y - x;
	Vector v1 = z - x;
	Vector r = v0.cross(v1);
	r.Normalize();
	return r;
}

inline Vector CrossProduct(Vector *v0, Vector *v1)
{
	return v0->cross(*v1);
}

inline float rrange(float min, float max)
{
	return((rand()*(max-min)/RAND_MAX)+min);
}

inline float LERP(float a, float b, float t)
{
	return (a - ((a * t) + (b * t)));
}

inline float dist(float a, float b, float c, float d)
{
	return (float)sqrt(((d - b) * (d - b)) + ((c - a) * (c - a)));
}


#endif			//__POL_MATH_MISC__
