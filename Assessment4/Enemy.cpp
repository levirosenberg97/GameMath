#include "Enemy.h"
#include "Transform.h"
#include <cmath>
#include"sfwdraw.h"
#include"mat3.h"
#include "Player.h"
#include<iostream>
#include "Emitter.h"
#include "mat3.h"


Enemy::Enemy()
{

}

Enemy::Enemy(float siz1)
{
	size1 = siz1;
}

void Enemy::draw(Transform a)
{
	//float t = sfw::getTime();

	//a.dim = vec2{ sinf(t) + 2, sinf(t) + 2 };

	if (enabled1 == true)
	{
		DrawMatrix(a.getLocalTransform(), size1);
	}
}

void Enemy::update(Player &dummy, Transform &a, Emitter &pea)
{
	float t = sfw::getTime();

	if (a.pos.x != dummy.myTrans.pos.x || a.pos.y != dummy.myTrans.pos.y)
	{
		if (a.pos.x < dummy.myTrans.pos.x)
		{
			//a.pos.x += speed;
		}

		if (a.pos.x > dummy.myTrans.pos.x)
		{
			//a.pos.x -= speed;
		}

		if (a.pos.y < dummy.myTrans.pos.y)
		{
		//	myTrans.pos.y += speed;
		}

		if (a.pos.y > dummy.myTrans.pos.y)
		{
		//	a.pos.y -= speed;
		}
	}


	if (dist(dummy.myTrans.pos, a.pos) < (size1 + dummy.radius) && enabled1 == true)
	{
		dummy.enabled = false;
	}

	for (int i = 0; i < 1; i++)
	{
		if (dist(a.pos, pea.particles[i].myTrans.pos) < (size1 + pea.particles[i].r) && pea.particles[i].enabled == true && enabled1 == true)
		{
			pea.particles[i].enabled = false;
			enabled1 = false;
		}

	}

}

// 2 ways
// Check against a radius

// Check against a box

// circle vs circle collision
// distance < combined radii