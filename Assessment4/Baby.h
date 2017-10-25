#pragma once
#include "Transform.h"
#include "Player.h"
#include "Emitter.h"

class Babys
{
public:
	Transform lilT;
	Babys();
	Babys(Transform &trans, float posX, float posY, float dimX, float dimY, float ang);
	bool enabled = true;
	void update(Player &ply, Emitter &pea, vec2 &eme, float rad);
	void draw(float rad);
};