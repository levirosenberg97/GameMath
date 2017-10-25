#pragma once
#include"vec2.h"
#include "mat3.h"

class Transform
{
public:
	vec2 pos;
	vec2 dim;
	float angle;
	Transform *e_parent;

	Transform();

	mat3 getLocalTransform() const;
	mat3 getGlobalTransform() const;

	vec2 getGlobalPosition() const
	{
		return getGlobalTransform()[2].xy;
	}
};


void DrawMatrix(const mat3 &t, float drawing_scale);


/*

[1 0 Tx]
[0 1 Ty]
[0 0 1 ]
*/