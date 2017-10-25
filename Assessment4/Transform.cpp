#include "Transform.h"
#include "sfwdraw.h"


Transform::Transform()
{
	pos = vec2{ 0,0 };
	dim = vec2{ 1,1 };
	angle = 0;
	e_parent = nullptr;
}

mat3 Transform::getLocalTransform() const
{
	return translate(pos) * scale(dim) * rotate(angle);
}

mat3 Transform::getGlobalTransform() const
{
	if (e_parent != nullptr)
	{
		return e_parent->getGlobalTransform() * getLocalTransform();
	}
	else
	{
		return getLocalTransform();
	}

}

void DrawMatrix(const mat3 & t, float drawing_scale)
{
	vec2 position = t[2].xy;
	sfw::drawCircle(position.x, position.y, drawing_scale);

}
