#include "Player.h"

bool doCollision(Player & player, const Wall & wall)
{
	auto hit = collides(player.transform, player.collider, wall.transform, wall.collider);

	if (hit.penDepth >= 0)
	{
		static_resolution(player.transform.pos, player.rigidbody.velocity, hit,1);
		return true;
	}
	return false;
}

bool doCollision(Ball & ball, const Wall & wall)
{
	auto hit = collides(ball.transform, ball.collider, wall.transform, wall.collider);

	if (hit.penDepth >= 0)
	{
		static_resolution(ball.transform.pos, ball.rigidbody.velocity, hit, 1);
		return true;
	}
	return false;
}

bool doCollision(Player & player, Ball & ball)
{
	auto hit = collides( player.transform, player.collider,ball.transform, ball.collider);

	if (hit.penDepth >= 0)
	{
		dynamic_resolution(player.transform.pos, player.rigidbody.velocity, player.rigidbody.mass, ball.transform.pos, ball.rigidbody.velocity, ball.rigidbody.mass, hit);
		return true;
	}
	return false;
}
