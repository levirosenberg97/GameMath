#include "Player.h"
#include "sfwdraw.h"
#include <iostream>
#include "mat3.h"

using namespace sfw;


void Player::draw()
{
	lineTransform.e_parent = &myTrans;
	if (enabled == true)
	{
		drawCircle(myTrans.pos.x, myTrans.pos.y, radius);
		drawLine(myTrans.pos.x, myTrans.pos.y, mouseTran.pos.x, mouseTran.pos.y, BLUE);
	}
}

void Player::update()
{
	movement();
	cursor();

}

//void Player::DrawTexture(unsigned sprite, const mat3 &t)
//{
//	drawTextureMatrix3(sprite, 0, WHITE, t.m);
//}

void Player::movement()
{
	if (getKey('W'))
	{
		myTrans.pos.y += speed;
	}

	if (getKey('S'))
	{
		myTrans.pos.y -= speed;
	}

	if (getKey('D'))
	{
		myTrans.pos.x += speed;
	}

	if (getKey('A'))
	{
		myTrans.pos.x -= speed;
	}
}

void Player::cursor()
{
	mouseTran.pos.x = getMouseX();
	mouseTran.pos.y = getMouseY();

	drawLine(mouseTran.pos.x, mouseTran.pos.y, mouseTran.pos.x + 4, mouseTran.pos.y,RED);
	drawLine(mouseTran.pos.x, mouseTran.pos.y, mouseTran.pos.x, mouseTran.pos.y - 6,RED);

}
