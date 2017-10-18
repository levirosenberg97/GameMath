#pragma once

#include "vec3.h"

union mat3
{
	vec3 c[3];
	float m[9];
	float mm[3][3];
	

	vec3 &operator[](size_t idx);             // column accessor
	const vec3 &operator[](size_t idx)const;

	static mat3 identity();					  // creates and returns an identity matrix
	
	static mat3 zero();

};

bool operator==(const mat3 &A, const mat3 &B);

mat3 operator +(const mat3 &A, const mat3 &B);// not really used
mat3 operator -(const mat3 &A, const mat3 &B);// not really used
mat3 operator *(const mat3 &A, const mat3 &B);// compine transformation
vec3 operator *(const mat3 &A, const vec3 &B);// apply a transformation

mat3 transpose(const mat3 &A);

float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);

/*	Translation
[1 0 X]
[0 1 Y]
[0 0 1]
*/
mat3 translate(const vec2 &t);

/*Scale
[X 0 0]
[0 Y 0]
[0 0 1]
*/
mat3 scale(const vec2 &s);


/*Rotation
[cos(a) -sin(a) 0]
[sin(a) cos(a)  0]
[  0      0     1]
*/

mat3 rotate(float deg);

/*
[1 0 x]
[0 1 y]
[0 0 1]


[0 3 6]
[1 4 7]
[2 5 8]


[(0,0) (0,1) (0,2)]
[(1,0) (1,1) (1,2)]
[(2,0) (2,1) (2,2)]


[c1 c2 c3]
*/