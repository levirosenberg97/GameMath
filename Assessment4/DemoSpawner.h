#pragma once
#include "hive.h"
#include "Player.h"

class SPawnEnemies
{
public:
	SPawnEnemies();
	Hive hive[5];
	float spawnInterval;
	float timer;
	void update(Player &object, Emitter &emit);
	void draw();
	
};