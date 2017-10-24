#pragma once
#include "vec2.h"


class Player
{
	
public:

	vec2 pos{640,300};
	float speed = 3;
	void draw();
	void update();
	void movement();
	bool enabled = true;
	float radius = 20;
};
