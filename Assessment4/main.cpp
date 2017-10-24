#include"mat3.h"
#include"vec2.h"
#include"sfwdraw.h"
#include"Player.h"
#include"Enemy.h"
#include"Transform.h"
#include "Particles.h"
#include "Emitter.h"

using namespace sfw;

int main()
{
	


	Player ply;
	Enemy eme;

	Emitter pea;

	

	sfw::initContext(1280, 600,"SFW");

	Transform myTransform;
	myTransform.pos = vec2{ 300,400 };
	myTransform.dim = vec2{ 2,2 };
	myTransform.angle = 0;

	Transform myBaby;
	myBaby.pos = vec2{ 10,10 };
	myBaby.dim = vec2{ 1,1 };
	myBaby.angle = 180;
	myBaby.e_parent = &myTransform;

	Transform myBaby2;
	myBaby2.pos = vec2{ -10,-10 };
	myBaby2.dim = vec2{ 1,1 };
	myBaby2.angle = 90;
	myBaby2.e_parent = &myTransform;

	Transform myBaby3;
	myBaby3.pos = vec2{ -20,-20 };
	myBaby3.dim = vec2{ 1,1 };
	myBaby3.angle = 90;
	myBaby3.e_parent = &myTransform;

	Transform myBaby4;
	myBaby4.pos = vec2{ 20,20 };
	myBaby4.dim = vec2{ 1,1 };
	myBaby4.angle = 180;
	myBaby4.e_parent = &myTransform;

	sfw::setBackgroundColor(BLACK);

	while (sfw::stepContext())
	{
		myTransform.angle += getDeltaTime() + 9;
		ply.draw();
		ply.update();
		eme.draw(myTransform,myBaby,myBaby2,myBaby3,myBaby4);
		eme.update(ply, myTransform);
		
		
			pea.draw(ply);
			pea.update(ply);


	}
	sfw::termContext();
}