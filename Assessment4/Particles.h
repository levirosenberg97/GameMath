#pragma once
#include "Player.h"
#include "Transform.h"
class BaseParticles
{

public:
	
	Transform myTrans;
	bool enabled;

	float speedX ;
	float speedY ;
	vec2 Dir;
	float speed;

	virtual void draw(Player object);
	virtual void update();
	
};