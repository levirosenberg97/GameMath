#pragma once
#include "vec2.h";
#include"Transform.h"
#include "Player.h"
#include "Emitter.h"
#include"Baby.h"
class Enemy
{
public:
	Enemy();
	Enemy(float siz1);
	Transform myTrans;
	float size1;
	void draw(Transform a, Babys &bby, Babys &bby2, Babys &bby3, Babys &bby4, Babys &bby5, Babys &bby6);
	void update(Player &dummy, Transform &a, Emitter &pea, Babys &bby, Babys &bby2, Babys &bby3, Babys &bby4, Babys &bby5, Babys &bby6);
	float speed = 2.5f;
	bool enabled1 = true;



};