#include "DrawShape.h"
#include "sfwdraw.h"


void drawCircle(const circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void drawRect(const AABB & C, int color)
{
	float x1 = C.position.x + C.extents.x;
	float x2 = C.position.x - C.extents.x;
	float y1 = C.position.y + C.extents.y;
	float y2 = C.position.y - C.extents.y;

	//Top
	sfw::drawLine(x2, y1, x1, y1, color);
	//Bottom
	sfw::drawLine(x2, y2, x1, y2, color);
	//Left
	sfw::drawLine(x2, y2, x2, y1, color);
	//Right
	sfw::drawLine(x1, y2, x1, y1, color);
}
