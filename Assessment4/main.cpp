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
#include"DemoSpawner.h"

using namespace sfw;

int main()
{
	
	Player ply;
	

	Emitter pea;
	
	SPawnEnemies beeHive;

	ply.myTrans.pos.x = 640;
	ply.myTrans.pos.y = 300;

	sfw::initContext(1280, 600,"SFW");





	sfw::setBackgroundColor(BLACK);

	while (sfw::stepContext())
	{
		
		ply.draw();
		ply.update();
		
		beeHive.draw();
		beeHive.update(ply, pea);


		pea.draw(ply);
		pea.update(ply);


	}
	sfw::termContext();
}