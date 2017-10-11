#include "Player.h"
#include "vec2.h"
#include"sfwdraw.h"

#include <iostream>

void Player::update()
{
	vec2 movement = { 0,0 };

	if (sfw::getKey('W'))
	{
		movement.y += 3;
	}
	if (sfw::getKey('S'))
	{
		movement.y -= 3;
	}
	if (sfw::getKey('A'))
	{
		movement.x -= 3;
	}
	if (sfw::getKey('D'))
	{
		movement.x += 3;
	}

	if (sfw::getKey(KEY_TAB))
	{
		time -= sfw::getDeltaTime();
		if (time > 0)
		{
			movement *= speed;
		}
		if (time <= 0)
		{
			time = 0;
		}
	}
	else
	{
		if (time < maxTime)
		{
			time += sfw::getDeltaTime();
		}
	}



	if (sfw::getKey(KEY_BACKSPACE))
	{
		if (teleTime <= 0)
		{
			pos.x = rand() % 1200 + 20;
			pos.y = rand() % 550 + 10;
			teleTime = 5;
		}
	}

	teleTime -= sfw::getDeltaTime();
	pos += movement;
}

void Player::draw()
{
	sfw::drawCircle(pos.x, pos.y, 30);
}