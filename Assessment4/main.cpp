#include"mat3.h"
#include"vec2.h"
#include"sfwdraw.h"
#include"Player.h"
#include"Enemy.h"
#include"Transform.h"
#include "Particles.h"
#include "Emitter.h"
#include "Baby.h"
#include "Spawner.h"

using namespace sfw;

int main()
{
	
	Player ply;
	Spawner eme;

	Emitter pea;
	


	ply.myTrans.pos.x = 640;
	ply.myTrans.pos.y = 300;

	sfw::initContext(1280, 600,"SFW");

	Transform myTransform;
	myTransform.pos = vec2{ 300,400 };
	myTransform.dim = vec2{ 2,2 };
	myTransform.angle = 0;

	Babys bby(myTransform, 15, 15, 1, 1, 0);
	Babys bby2(myTransform,	-15, -15, 1, 1, 180);
	Babys bby3(myTransform, -25, 25, 1, 1, 300);
	Babys bby4(myTransform, 25, -25, 1, 1, 140);
	Babys bby5(myTransform, 25, 25, 1, 1, 300);
	Babys bby6(myTransform, -25, -25, 1, 1, 140);


	sfw::setBackgroundColor(BLACK);

	while (sfw::stepContext())
	{
		myTransform.angle += getDeltaTime() + 10;
		ply.draw();
		ply.update();
		eme.draw(myTransform);
		eme.update(ply, myTransform, pea);
		bby.draw(15);
		bby2.draw(15);
		bby3.draw(8);
		bby4.draw(8);
		bby5.draw(8);
		bby6.draw(8);

		bby.update(ply,pea,eme,15);
		bby2.update(ply, pea, eme, 15);
		bby3.update(ply, pea, eme, 8);
		bby4.update(ply, pea, eme, 8);
		bby5.update(ply, pea, eme, 8);
		bby6.update(ply, pea, eme, 8);


		pea.draw(ply);
		pea.update(ply);


	}
	sfw::termContext();
}