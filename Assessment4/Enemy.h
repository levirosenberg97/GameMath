#pragma once
#include "vec2.h";
#include"Transform.h"
#include "Player.h"

class Enemy
{
public:
	vec2 posi{200,100};
	float size = 50;
	void draw(Transform a, Transform b, Transform c, Transform d, Transform e);
	void update(Player &dummy, Transform &a);
	bool enabled = true;
};