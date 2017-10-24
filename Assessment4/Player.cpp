#include "Player.h"
#include "sfwdraw.h"
#include <iostream>
#include "mat3.h"

using namespace sfw;


void Player::draw()
{
	if (enabled == true)
	{
		drawCircle(pos.x, pos.y, radius);
	}
}

void Player::update()
{
	movement();
}

//void Player::DrawTexture(unsigned sprite, const mat3 &t)
//{
//	drawTextureMatrix3(sprite, 0, WHITE, t.m);
//}

void Player::movement()
{
	if (getKey('W'))
	{
		pos.y += speed;
	}

	if (getKey('S'))
	{
		pos.y -= speed;
	}

	if (getKey('D'))
	{
		pos.x += speed;
	}

	if (getKey('A'))
	{
		pos.x -= speed;
	}
}
