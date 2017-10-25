#pragma once
#include "vec2.h";
#include"Transform.h"
#include "Player.h"
#include "Emitter.h"
class Enemy
{
public:
	Enemy();
	Enemy(float siz1);
	Transform myTrans;
	float size1;
	void draw(Transform a);
	void update(Player &dummy, Transform &a, Emitter &pea);
	float speed = 2.5f;
	bool enabled1 = true;
};