#include "Block.h"

using namespace sfw;

bool doCollision(Player & player, const Block & block, bool &grounded)
{
	auto hit = collides(player.transform, player.collider, block.transform, block.collider);

	if (hit.penDepth == 0 && hit.axis.y == 1 && grounded == false)
	{
		if(hit.handedness >= 0)
			grounded = true;

		//double team
		//player.rigidbody.velocity *= -1;

		player.rigidbody.velocity.y = 0;
	}

	if (hit.penDepth > 0)
	{
		static_resolution(player.transform.pos, player.rigidbody.velocity, hit, .8, grounded);
		return true;
		if (hit.axis.y == 1)
		{
			player.rigidbody.velocity *= -1;
		}
	}
	return false;
}

bool doCollision(Enemy &enemy, const Block &block, bool&grounded)
{
	auto hit = collides(enemy.transform, enemy.collider, block.transform, block.collider);
	

	if (hit.penDepth == 0 && hit.axis.y == 1 && grounded == false)
	{
		if (hit.handedness >= 0)
			grounded = true;

		enemy.rigidbody.velocity.y = 0;
	}

	if (hit.penDepth > 0)
	{
		if (fabs(hit.axis.x) == 1)
			enemy.xSpeed = -enemy.xSpeed;

		static_resolution(enemy.transform.pos, enemy.rigidbody.velocity, hit, .8, grounded);
		return true;

		if (hit.axis.y == 1)
		{
			enemy.rigidbody.velocity *= -1;
		}
	}
	return false;
}

bool doCollision(Enemy &enemy, Player &player, Scoreboard &score)
{
	auto hit = collides(enemy.transform, enemy.collider, player.transform, player.collider);

	if (hit.penDepth >= 0)
	{
		if (fabs(hit.axis.x) == 1 && enemy.alive == true)
		{
			player.alive = false;
			
		}
		if (fabs(hit.axis.y) == 1 && player.alive == true)
		{
			enemy.alive = false;
			score.score+= 15;
		}
		dynamic_resolution(enemy.transform.pos, enemy.rigidbody.velocity,enemy.rigidbody.mass,player.transform.pos,player.rigidbody.velocity,player.rigidbody.mass,hit, 5);
		return true;
	}

	return false;
}

void drawBox(const AABB & C, int color)
{
	float x1 = C.position.x + C.extents.x;
	float x2 = C.position.x - C.extents.x;
	float y1 = C.position.y + C.extents.y;
	float y2 = C.position.y - C.extents.y;

	//Top
	sfw::drawLine(x2, y1, x1, y1, color);
	//Bottom
	sfw::drawLine(x2, y2, x1, y2, color);
	//Left
	sfw::drawLine(x2, y2, x2, y1, color);
	//Right
	sfw::drawLine(x1, y2, x1, y1, color);
}

void Enemy::update(Player player)
{
	rigidbody.velocity.x = xSpeed;
	if (xSpeed > 0 && transform.dim.x > 0)
		transform.dim.x *= -1;
	else if (xSpeed < 0 && transform.dim.x < 0)
		transform.dim.x *= -1;
	//rigidbody.integrate(transform, sfw::getDeltaTime());
}
