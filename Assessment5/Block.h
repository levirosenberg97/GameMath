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

	bool alive;
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
	Rigidbody rigidbody;
	bool alive;
	float xSpeed;
	bool grounded;

	void update(Player);

	Enemy()
	{
		grounded = false;
		xSpeed = -100;
	}

};

bool doCollision(Enemy&, const Block&, bool&);
bool doCollision(Player &player, const Block &block, bool&);
bool doCollision(Enemy&, Player&);


void drawBox(const AABB & C, int color);