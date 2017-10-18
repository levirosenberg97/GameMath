#include "vec3.h"

#include "mathutils.h"
#include <cmath>
#include<cfloat>

float & vec3::operator[](unsigned idx)
{
	return v[idx];
}

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}

vec3 operator+(const vec3 &lhs, const vec3 &rhs)
{
	vec3 result;

	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	result.z = lhs.z + rhs.z;
	return result;
}

vec3 operator+=( vec3 &lhs, const vec3 &rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

bool operator==(const vec3 &lhs, const vec3 & rhs)
{
	if (abs(lhs.x - rhs.x) < EPSILON &&
		abs(lhs.y - rhs.y) < EPSILON &&
		abs(lhs.z - rhs.z) < EPSILON)
	{
		return true;
	}
	return false;
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	vec3 result;
	for (int i = 0; i < 3; i++)
	{
		result.v[i] = lhs.v[i] - rhs.v[i];
	}
	return result;
}

vec3 operator*(const vec3 & lhs, const float num)
{
	return{ lhs.x * num,lhs.y * num , lhs.z * num};
}

vec3 operator*(const float num, const vec3 & rhs)
{
	return{ rhs.x * num,rhs.y * num , rhs.z * num };
}

vec3 operator/(const vec3 & lhs, const float num)
{
	return{ lhs.x / num,lhs.y / num,lhs.z / num };
}

vec3 operator-(const vec3 & rhs)
{
	return{ rhs.x * -1,rhs.y * -1 , rhs.z * -1 };
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	if (abs(lhs.x - rhs.x) > EPSILON &&
		abs(lhs.y - rhs.y) > EPSILON &&
		abs(lhs.z - rhs.z) > EPSILON)
	{
		return true;
	}
	return false;
}

vec3 & operator-=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

vec3 &operator*=(vec3 & lhs, const float num)
{
	lhs = lhs * num;
	return lhs;
}

vec3 & operator/=(vec3 & lhs, const float num)
{
	lhs = lhs / num;
	return lhs;
}

float dot(const vec3 &lhs, const vec3 & rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z *rhs.z;
}

float mag(vec3 & lhs)
{
	return sqrtf(sqr(lhs.x) + sqr(lhs.y) + sqr(lhs.z));
}

float dist(const vec3 & a, const vec3 & b)
{
	return mag(b - a);
}

vec3 lerp(const vec3 & s, const vec3 & e, float a)
{
	return s + a * (e - s);
}

vec3 min(const vec3 & a, const vec3 & b)
{
	vec3 temp;
	temp.x = min(a.x, b.x);
	temp.y = min(a.y, b.y);
	temp.z = min(a.z, b.z);

	return temp;
}

vec3 max(const vec3 & a, const vec3 & b)
{
	vec3 temp;
	temp.x = max(a.x, b.x);
	temp.y = max(a.y, b.y);
	temp.z = max(a.z, b.z);

	return temp;
}

vec3 nrm(vec3 lhs)
{
	float magaz = mag(lhs);
	lhs.y = lhs.y / magaz;
	lhs.x = lhs.x / magaz;
	lhs.z = lhs.z / magaz;
	return lhs;
}

vec3 nrmRef(vec3 & lhs)
{
	lhs = nrm(lhs);
	return lhs;
}

vec3 clmp(const vec3 & lhs, const vec3 & min, const vec3 & max)
{
	vec3 result = lhs;

	for (int i = 0; i < 3; i++)
	{
		if (result.v[i] <= max.v[i])
		{
			result.v[i] = max.v[i];
		}

		if (result.v[i] >= max.v[i])
		{
			result.v[i] = max.v[i];
		}
	}

	return result;
}

vec3 cross(const vec3 & a, const vec3 & b)
{
	return vec3 {a.y*b.z - a.z*b.y,
				 a.z*b.x - a.x*b.z,
				 a.x*b.y - a.y*b.x};
}
