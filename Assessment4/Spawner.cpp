#include "Spawner.h"
#include "vec2.h"
#include "sfwdraw.h"
#include <time.h>
#include<iostream>
#include"Player.h"

Spawner::Spawner()
{
	for (int i = 0; i < 1; i++)
	{
		enemies[i].enabled1 = false;
	}
	srand(time(NULL));
	spawnAcc = 3;
}

void Spawner::draw(Transform myTran)
{
	for (int i = 0; i < 1; i++)
	{
		// only draw active particles
		if (enemies[i].enabled1)
		{
			enemies[i].draw(myTran);
		}
	}
}

void Spawner::update(Player &object, Transform &myTran, Emitter &pea)
{
	timer += sfw::getDeltaTime();
	if (timer > spawnAcc)
	{
		timer = 0;
		std::cout << "BABIES";
		for (int i = 0; i < 10; i++)
		{
			if (enemies[i].enabled1 == false)
			{
				Enemy &baby = enemies[i];
				if (baby.myTrans.pos.x == 0 || baby.myTrans.pos.y == 0 || (baby.myTrans.pos.x <= object.myTrans.pos.x + 50 && baby.myTrans.pos.y <= object.myTrans.pos.y + 50))
				{
					baby.myTrans.pos = vec2{ (float)(rand() % 1280 + 1),(float)(rand() % 600 + 1) };
				}
				baby.size1 = 15;

				baby.enabled1 = true;

				//spawnAcc = 0.0f;
				break;
			}
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		if (enemies[i].enabled1 == true)
		{
			enemies[i].update(object, myTran, pea);
		}
	}
}
