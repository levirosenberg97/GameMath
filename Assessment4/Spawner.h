#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Baby.h"

class Spawner
{

	float spawnAcc;

public:
	Spawner();

	Enemy enemies[10];

	int enemyID;
	float timer = 0;
	void draw(Transform myTran, Babys &bby, Babys &bby2, Babys &bby3, Babys &bby4, Babys &bby5, Babys &bby6);
	void update(Player &object, Transform &myTran, Emitter &pea, Babys &bby, Babys &bby2, Babys &bby3, Babys &bby4, Babys &bby5, Babys &bby6);

};