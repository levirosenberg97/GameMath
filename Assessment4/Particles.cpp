#include "Particles.h"
#include "sfwdraw.h"


void BaseParticles::draw(Player object)
{
	r = object.radius / 10;
	sfw::drawCircle(myTrans.pos.x, myTrans.pos.y, r);
}

void BaseParticles::update()
{
	myTrans.pos += (Dir * speed);

}


