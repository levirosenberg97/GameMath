#pragma once

#include "sfwdraw.h"
#include "vec2.h"
#include "Sprite.h"
#include "Controller.h"
#include "Collider.h"


class Player
{		
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Controller controller;
	Sprite sprite;
};

class Wall
{
public:
	Transform transform;
	Sprite sprite;
	Collider collider;
};

class Ball
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Sprite sprite;
};


bool doCollision(Player &player,const Wall &wall);
bool doCollision(Ball &ball, const Wall &wall);
bool doCollision(Player &player, Ball &ball);