#pragma once
#include "vec2.h"
#include "Transform.h"

class Player
{
	
public:
	

	Transform myTrans;
	Transform mouseTran;
	Transform lineTransform;

	float speed = 3;
	void draw();
	void update();
	void movement();
	void cursor();
	bool enabled = true;
	float radius = 20;
};
