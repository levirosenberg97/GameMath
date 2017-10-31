 #include "Transform.h"
#include "sfwdraw.h"


Transform::Transform()
{
	pos = vec2{ 0,0 };
	dim = vec2{ 0,0 };
	angle = 0;
	e_parent = nullptr;
}

mat3 Transform::getLocalTransform() const
{
	return translate(pos) * scale(dim) * rotate (angle);
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
	vec2 right_ep = position + t[0].xy * drawing_scale;
	vec2 up_ep = position + t[1].xy * drawing_scale;

	sfw::drawLine(position.x, position.y, right_ep.x, right_ep.y, RED);
	sfw::drawLine(position.x, position.y, up_ep.x, up_ep.y, GREEN);

	sfw::drawCircle(position.x, position.y, drawing_scale / 4);

}
