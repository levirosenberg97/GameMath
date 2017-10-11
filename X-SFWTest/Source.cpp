#include "sfwdraw.h"
#include"vec2.h"
#include "Player.h"

int main()
{
	sfw::initContext(1280,600);

	Player me;
	me.pos = { 400,300 };
	me.speed = 5;
	me.teleTime = 10.0f;
	me.maxTime = 10;
	me.maxtele = 10;

	while (sfw::stepContext())
	{
		me.update();
		me.draw();
	}

	sfw::termContext();

}