#include "vec2.h"
#include "mathutils.h"
#include <cfloat>
#include<cmath>

float vec2::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec2::operator[](unsigned idx)
{
	return v[idx];
}



vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	// vec2 + vec2
	return{ lhs.x + rhs.x,lhs.y + rhs.y };
}

vec2 &operator+=(vec2 & lhs, const vec2 & rhs)
{
	// int a = 5
	// a += 4;
	lhs = lhs + rhs;

	return lhs;
}

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON && abs(lhs.y - rhs.y) < FLT_EPSILON)
	{
		return true;
	}

	return false;
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return{ lhs.x - rhs.x,lhs.y - rhs.y };
}

vec2 operator*(const vec2 & lhs, const float num )
{
	return{ lhs.x * num,lhs.y * num };
}

vec2 operator*(const float num, const vec2 & rhs)
{
	return{ rhs * num };
}

vec2 operator/(const vec2 & lhs, const float num)
{
	return{ lhs.x / num,lhs.y / num };
}

vec2 operator-(const vec2 & rhs)
{
	return{ rhs.x * -1,rhs.y * -1 };
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	if (abs(lhs.x - rhs.x) > FLT_EPSILON && abs(lhs.y - rhs.y) > FLT_EPSILON)
	{
		return true;
	}

	return false;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	lhs = lhs - rhs;

	return lhs;
}

vec2 &operator*=( vec2 & lhs, const float num)
{
	lhs.x = lhs.x * num;
	lhs.y = lhs.y * num;
	return lhs;	
}

vec2 & operator/=(vec2 & lhs, const float num)
{
	lhs.x = lhs.x / num;
	lhs.y = lhs.y / num;
	return lhs;
}

float sqr(float x)
{
	return x * x;
}

float dot(const vec2 &lhs, const vec2 & rhs)
{
	return lhs.x * rhs.x+ lhs.y * rhs.y;
}

float dist(const vec2 & a, const vec2 & b)
{
	return mag(b - a);
}

vec2 perp(const vec2 & v)
{
	return vec2{ v.y,-v.x };
}

vec2 lerp(const vec2 & s, const vec2 & e, float a)
{
	return s + a * (e - s);
}

vec2 min(const vec2 & a, const vec2 & b)
{
	vec2 temp;
	temp.x = min(a.x, b.x);
	temp.y = min(a.y, b.y);

	return temp;
}

vec2 max(const vec2 & a, const vec2 & b)
{
	vec2 temp;
	temp.x = max(a.x, b.x);
	temp.y = max(a.y, b.y);

	return temp;
}

float mag(vec2 & lhs)
{
	return sqrtf(sqr(lhs.x) + sqr(lhs.y));
}

vec2 nrm(vec2 lhs)
{
	float magaz= mag(lhs);
	lhs.y = lhs.y / magaz;
	lhs.x = lhs.x / magaz;
	return lhs;
}

vec2 nrmRef(vec2 & lhs)
{
	lhs = nrm(lhs);
	return lhs;
}