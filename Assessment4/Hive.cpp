#include "Hive.h"
#include "sfwdraw.h"

using namespace sfw;
Hive::Hive()
{
	bees[0].lilT.pos = { -45,45 };
	bees[1].lilT.pos = { 45,-45 };
	bees[2].lilT.pos = { 85,85 };
	bees[3].lilT.pos = { -85,85 };
	bees[4].lilT.pos = { 85,-85 };
	bees[5].lilT.pos = { -85,-85 };

	bees[0].radius = 20;
	bees[1].radius = 20;
	bees[2].radius = 10;
	bees[3].radius = 10;
	bees[4].radius = 10;
	bees[5].radius = 10;

	rad = 30;
	
	for (int i = 0; i < 6; i++)
	{
		bees[i].lilT.dim = { 1,1 };
		bees[i].lilT.angle = 0;
		//set up the bees  dim, angle
		//assign bees.parent = hiveT
		speed = 0.5f;
		bees[i].enabled = true;
		bees[i].lilT.e_parent = &hiveT;
		//set my bees radius

	}
}

void Hive::update(Player &object, Emitter &emit)
{
	for (int i = 0; i < 6; i++)
	{
		//update our bees
		bees[i].update(object, emit);
	}

	if (dist(hiveT.pos, object.myTrans.pos) < (rad + object.radius) && enabled == true)
	{
		object.enabled = false;
	}

	for (int i = 0; i < 1; i++)
	{
		if (dist(hiveT.pos, emit.particles[i].myTrans.pos) < (rad + emit.particles[i].r) && enabled == true)
		{
			emit.particles[i].enabled = false;
			enabled = false;
		}
	}

	//updating the hive loigc
	//move hive towards player
	if (hiveT.pos != object.myTrans.pos)
	{
		if (hiveT.pos.x <= object.myTrans.pos.x)
		{
			hiveT.pos.x += speed;
		}

		if (hiveT.pos.x >= object.myTrans.pos.x)
		{
			hiveT.pos.x -= speed;
		}

		if (hiveT.pos.y <= object.myTrans.pos.y)
		{
			hiveT.pos.y += speed;
		}

		if (hiveT.pos.y >= object.myTrans.pos.y)
		{
			hiveT.pos.y -= speed;
		}

	}

	//rotate the hive
	hiveT.angle += getDeltaTime() + 5;
}

void Hive::draw()
{
	//draw the hive
	if (enabled = true)
	{
		drawCircle(hiveT.pos.x, hiveT.pos.y, rad);
	}
	for (int i = 0; i < 6; i++)
	{
		//draw the bees
		bees[i].draw();
	}
}

void Bee::update(Player &object, Emitter &emit)
{
	if(dist(lilT.getGlobalPosition(), object.myTrans.pos) < (radius + object.radius) && enabled == true)
	{
		object.enabled = false;
	}
	for (int i = 0; i < 1; i++)
	{
		if (dist(lilT.getGlobalPosition(), emit.particles[i].myTrans.pos) < (radius + emit.particles[i].r))
		{
			emit.particles[i].enabled = false;
			enabled = false;
		}

	}
}

void Bee::draw()
{
	if (enabled == true)
	{
		drawCircle(lilT.getGlobalPosition().x, lilT.getGlobalPosition().y, radius, 12, YELLOW);
	}
}
