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


#ifndef __POL_VECTOR__
#define __POL_VECTOR__


#include "../../poleaxe.h"
#include <math.h>


 typedef class Vector
{
	public:
		Vector()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		Vector(float x1, float y1, float z1)
		{
			x = x1;
			y = y1;
			z = z1;
		}

		Vector(float v[3])
		{
			x = v[0];
			y = v[1];
			z = v[2];
		}

		inline void operator *=(float scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
		}

		Vector operator +(Vector v)
		{
			Vector r;
			r.x += v.x;
			r.y += v.y;
			r.z += v.z;
			return r;
		}

		Vector operator -(Vector v)
		{
			Vector r;
			r.x -= v.x;
			r.y -= v.y;
			r.z -= v.z;
			return r;
		}

		inline float dot(Vector v)
		{
			return ((x*v.x) + (y*v.y) + (z*v.z));
		}

		Vector cross(Vector v)
		{
			Vector r;
			r.x = (y*v.z)-(z*v.y);
			r.y = -((x*v.z)-(z*v.x));
			r.z = (x*v.y)-(y*v.x);
			return r;
		}

		inline void Normalize()
		{
			float i = 1/Magnitude();
			x *= i;
			y *= i;
			z *= i;
		}

		inline float Magnitude()
		{
			return (sqrtf((x * x) + (y * y) + (z * z)));
		}

		inline void Set(float x1, float y1, float z1)
		{
			x = x1;
			y = y1;
			z = z1;
		}

		inline float *Get()
		{
			float *v = (float *)malloc(sizeof(float) * 3);
			v[0] = x;
			v[1] = y;
			v[2] = z;
			return v;
		}

		float x, y, z;
} Vector;


#endif			//__POL_VECTOR__
