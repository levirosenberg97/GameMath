#include "Enemy.h"
#include "Transform.h"
#include <cmath>
#include"sfwdraw.h"
#include"mat3.h"
#include "Player.h"
#include<iostream>


void Enemy::draw(Transform a, Transform b, Transform c, Transform d, Transform e)
{
	float t = sfw::getTime();

	
	a.dim = vec2{ sinf(t) + 2, sinf(t) + 2 };
	DrawMatrix(a.getLocalTransform(),size);
	DrawMatrix(b.getGlobalTransform(), size/2);
	DrawMatrix(c.getGlobalTransform(), size/2);
	DrawMatrix(d.getGlobalTransform(), size/3);
	DrawMatrix(e.getGlobalTransform(), size/3);
}

void Enemy::update(Player &dummy, Transform &a)
{
	if (dist(dummy.pos, a.pos) < (size + dummy.radius))
	{
		std::cout <<"Collided"; 
		dummy.enabled = false;
	}
}

// 2 ways
// Check against a radius

// Check against a box

// circle vs circle collision
// distance < combined radii