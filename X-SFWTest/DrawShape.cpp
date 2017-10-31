#include "DrawShape.h"
#include "sfwdraw.h"


void drawCircle(const circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void drawRect(const circle & C)
{
	float x1 = C.position.x + C.radius;
	float x2 = C.position.x - C.radius;
	float y1 = C.position.y + C.radius;
	float y2 = C.position.y - C.radius;

	//Top
	sfw::drawLine(x2, y1, x1, y1);
	//Bottom
	sfw::drawLine(x2, y2, x1, y2);
	//Left
	sfw::drawLine(x2, y2, x2, y1);
	//Right
	sfw::drawLine(x1, y2, x1, y1);
}
