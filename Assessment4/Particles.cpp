#include "Particles.h"
#include "sfwdraw.h"


void BaseParticles::draw(Player object)
{
	/*posX = object.pos.x + object.radius;
	posY = object.pos.y + object.radius;*/
	sfw::drawCircle(myTrans.pos.x, myTrans.pos.y, object.radius / 10);
}

void BaseParticles::update()
{
	myTrans.pos += (Dir * speed);
	/*myTrans.pos.x += speedX;
	myTrans.pos.y += speedY;*/
}


