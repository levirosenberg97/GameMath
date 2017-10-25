#pragma once
#include "Player.h"
#include "Transform.h"
class BaseParticles
{

public:
	
	Transform myTrans;
	bool enabled;

	vec2 Dir;
	float speed;

	float r;

	virtual void draw(Player object);
	virtual void update();
	
};