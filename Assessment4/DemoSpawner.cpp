#include "DemoSpawner.h"
#include "sfwdraw.h"
#include <random>

SPawnEnemies::SPawnEnemies()
{
	for (int i = 0; i < 5; i++)
	{
		//emabled = false
		hive[i].enabled = false;
		//set up transform data
		hive[i].hiveT.pos = { (float)(rand() % 1280 + 1),(float)(rand() % 600 + 1) };
	}
	spawnInterval = 1;
	timer = 0;
}

void SPawnEnemies::update(Player &object, Emitter &emit)
{
	timer += sfw::getDeltaTime();
	if (timer > spawnInterval)
	{
		timer = 0;
		for (int i = 0; i < 5; i++)
		{
			if (hive[i].enabled == false)
			{
				
				// set the position
				hive[i].hiveT.pos = { (float)(rand() % 1280 + 1),(float)(rand() % 600 + 1) };

				for (int j = 0; j < 6; j++)
				{
					hive[i].bees[j].enabled = true;
				}
				//dir to go towards the player
				

				if (hive[i].hiveT.pos.x <= object.myTrans.pos.x + 150 && hive[i].hiveT.pos.y <= object.myTrans.pos.y + 150 && hive[i].hiveT.pos.y >= object.myTrans.pos.y - 150 && hive[i].hiveT.pos.x >= object.myTrans.pos.x - 150)
				{
					hive[i].hiveT.pos = { (float)(rand() % 1280 + 1),(float)(rand() % 600 + 1) };
				}
				else
				{
					//enable it
					hive[i].enabled = true;
					break;
				}


			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (hive[i].enabled)
		{
			hive[i].update(object, emit);
		}
		
	}
}

void SPawnEnemies::draw()
{
	for (int i = 0; i < 5; i++)
	{
		if (hive[i].enabled)
		{
			hive[i].draw();
		}
	}
}
