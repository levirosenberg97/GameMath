#pragma once
#include"vec2.h"
#include "mat3.h"

class Transform
{
public:
	vec2 pos;
	vec2 dim;
	float angle;

	Transform();

	mat3 getLocalTransform() const;
};


void DrawMatrix(const mat3 &t, float drawing_scale);