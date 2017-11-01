#pragma once

union vec2
{
	//access by array
	float v[2];

	//access by individual component
	struct { float x, y; };

	float operator[](unsigned idx)const;
	float &operator[](unsigned idx);
};

vec2 operator+(const vec2 &lhs, const vec2 &rhs);

vec2 &operator+= (vec2 &lhs, const vec2 &rhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);

vec2 operator- (const vec2 &lhs, const vec2 &rhs);

vec2 operator*(const vec2 &lhs, const float num);

vec2 operator*(const float num, const vec2 & rhs);

vec2 operator/(const vec2 &lhs, const float num);

vec2 operator-(const vec2 &rhs);

bool operator!=(const vec2 &lhs, const vec2 &rhs);

vec2 &operator-= (vec2 &lhs, const vec2 &rhs);

vec2 &operator*=(vec2 & lhs, const float num);

vec2 &operator/=(vec2 & lhs, const float num);

float mag(const vec2 & lhs);

vec2 nrm( vec2  lhs);

vec2 nrmRef(vec2 &lhs);

float sqr(float x);

float dot(const vec2 &lhs, const vec2 & rhs);

float dist(const vec2 &a, const vec2 &b);

vec2 perp(const vec2 &v);

vec2 lerp(const vec2&s, const vec2 &e, float a);

vec2 min(const vec2 &a, const vec2 &b);

vec2 max(const vec2 &a, const vec2 &b);
vec2 project(const vec2 &v, const vec2 &axis);

vec2 reflect(const vec2 &v, const vec2 &axis);