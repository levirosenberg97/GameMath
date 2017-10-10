#include "mathutils.h"

#define _USE_MATH_DEFINES
#include<cmath>

float sqr(float v)
{
	return v * v;
}

float dbl(float v)
{
	return v + v;
}

float cube(float v)
{
	return sqr(v) * v;
}

float degToRad(float deg)
{
	return deg * (M_PI/ 180);
}

float radToDeg(float rad)
{
	return rad * (180 / M_PI);
}

float quad(float x)
{
	return sqr(x) + dbl(x) - 7;
}

float lin(float s, float e, float t)
{
	return s + t*(e - s);
}

float dist(float x1, float y1, float x2, float y2)
{
	return sqrt(sqr(x2 - x1) + sqr(y2 - y1));
}

float quadPos(float a, float b, float c)
{
	return (-b + sqrt(sqr(b) - (4 * a*c)))/ dbl(a);
}

float quadNeg(float a, float b, float c)
{
	return (-b - sqrt(sqr(b) - (4 * a * c))) / dbl(a);
}

float ppDis(float a, float b, float c, float d, float x, float y, float z)
{
	return ((a*x) + (b*y) + (c*z) + d) / sqrt(sqr(a) + sqr(b) + sqr(c));
}

float cbez(float t, float p0, float p1, float p2, float p3)
{
	return cube(1 - t)*p0 + 3 * sqr(1 - t)*(t*p1) + 3 * (1 - t)*sqr(t)*p2 + cube(t)*p3;
}
