#pragma once

#include "vec2.h"

union vec3
{
	//access by array
	float v[3];

	// access by individual component
	struct { float x, y, z; };

	//access to vec3 by index
	float &operator[](unsigned idx);
	float operator[](unsigned idx)const;

	//access as vec2
	vec2 xy;
};

vec3 operator+(const vec3 &lhs, const vec3 &rhs);

vec3 operator+=( vec3 &lhs, const vec3 &rhs);

bool operator==(const vec3 &lhs, const vec3 &rhs);

vec3 operator-(const vec3 & lhs, const vec3 & rhs);

vec3 operator*(const vec3 & lhs, const float num);

vec3 operator*(const float num, const vec3 & rhs);

vec3 operator/(const vec3 & lhs, const float num);

vec3 operator-(const vec3 & rhs);

bool operator!=(const vec3 & lhs, const vec3 & rhs);

vec3 & operator-=(vec3 & lhs, const vec3 & rhs);

vec3 &operator*=(vec3 & lhs, const float num);

vec3 & operator/=(vec3 & lhs, const float num);

float dot(const vec3 &lhs, const vec3 & rhs);

float mag(vec3 & lhs);

float dist(const vec3 & a, const vec3 & b);

vec3 lerp(const vec3 & s, const vec3 & e, float a);

vec3 min(const vec3 & a, const vec3 & b);

vec3 max(const vec3 & a, const vec3 & b);

vec3 nrm(vec3 lhs);

vec3 nrmRef(vec3 & lhs);

vec3 clmp(const vec3 &lhs, const vec3 min, const vec3 max);