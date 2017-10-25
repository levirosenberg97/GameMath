#pragma once
#include "Enemy.h"
#include "Player.h"

class Spawner
{

	float spawnAcc;

public:
	Spawner();

	Enemy enemies[10];

	int enemyID;
	float timer = 0;
	void draw(Transform myTran);
	void update(Player &object, Transform &myTran, Emitter &pea);

};