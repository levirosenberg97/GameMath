#pragma once
#include "Transform.h"
#include "Player.h"
#include "Emitter.h"

class Bee
{
public:
	Transform lilT;
	float radius;
	bool enabled;
	void update(Player &object, Emitter &emit);
	void draw();
};

class Hive
{
public:
	Transform hiveT;
	Bee bees[6];
	Hive();
	bool enabled;
	void update(Player &object, Emitter &emit);
	void draw();
	float speed;
	float rad;
};