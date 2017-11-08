#pragma once
#include "mathutils.h"
#include <cmath>
#include "shapes.h"

struct Collision
{
	float penDepth;
	float handedness;
	vec2 axis;

	Collision()
	{
		penDepth = -1;
	}
};

Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax);

Collision intersect_AABB(const AABB &A, const AABB &B);

Collision intersect_circle(const circle &A, const circle &B);

Collision intersect_AABB_circle(const AABB &A, const circle &B);

void static_resolution(vec2 &pos, vec2 &vel, const Collision &hit, float elasticity, bool&);

void dynamic_resolution(vec2 &Apos, vec2 &Avel, float Amass, vec2 &Bpos, vec2 &Bvel, float Bmass, const Collision &hit, float elasticity = 1.0f);