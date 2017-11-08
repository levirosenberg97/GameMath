#pragma once
#include "sfwdraw.h"
#include "Collision.h"
#include "vec2.h"
#include "Controller.h"
#include "Colliding.h"
#include "Sprite.h"

class Block
{
public:
	Collider collider;
	Transform transform;
	Sprite sprite;
};

class Player
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Controller controller;
	Sprite sprite;

	bool grounded;

	Player() 
	{
		grounded = false;
		rigidbody.drag = 5.f; 
	}
};

class Enemy
{
public:
	Collider collider;
	Sprite sprite;
	Transform transform;
};


bool doCollision(Player &player, const Block &block);
void drawBox(const AABB & C, int color);