#pragma once
#include "mathutils.h"
#include <cmath>
#include "shapes.h"

struct Collision
{
	float penDepth;
	float handedness;
	vec2 axis;
};

Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax);

Collision intersect_AABB(const AABB &A, const AABB &B);

Collision intersect_circle(const circle &A, const circle &B);

Collision intersect_AABB_circle(const AABB &A, const circle &B);