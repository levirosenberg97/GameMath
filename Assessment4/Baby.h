#pragma once
#include "Transform.h"
#include "Player.h"
#include "Emitter.h"
#include "Spawner.h"

class Babys
{
public:
	Transform lilT;
	Babys(Transform &trans, float posX, float posY, float dimX, float dimY, float ang);
	bool enabled = true;
	void update(Player &ply, Emitter &pea, Spawner &eme, float rad);
	void draw(float rad);
};