#include "sfwdraw.h"
#include "Block.h"
#include "vec2.h"

using namespace sfw;

int main()
{
	int size = 4;

	initContext(1280, 720);

	setBackgroundColor(WHITE);

	Block floor[4];
	floor[0].transform.pos = vec2{ 640,-100 };
	floor[0].transform.dim = { 1378,343 };
	floor[0].collider.box.extents = { .5,.5 };

	//Block wall;
	floor[1].transform.pos = vec2{ 0,365 };
	floor[1].transform.dim = { 50,590 };
	floor[1].transform.angle = 90;
	floor[1].collider.box.extents = { .5,.5 };
	
	floor[2].transform.pos = vec2{ 340,350 };
	floor[2].transform.dim = { 50,50 };
	floor[2].collider.box.extents = { .5,.5 };




	Player player;
	player.transform.dim = { 64.6f,144.6f };
	player.transform.pos = { 240,60 };
	player.collider.box.extents = { .5,.5 };
	player.sprite = loadTextureMap("Player.png");
	player.alive = true;

	Enemy enemy;
	enemy.transform.dim = { 59,73 };
	enemy.transform.pos = { 1100,60 };
	enemy.collider.box.extents = { .5,.5 };
	enemy.sprite = loadTextureMap("Enemy.png");
	enemy.alive = true;

	for (int i = 0; i < size; i++)
	{
		floor[i].sprite = loadTextureMap("Wall.png");
	}

	while(stepContext())
	{
		float dt = getDeltaTime();

		if (player.alive == true)
		{
			player.grounded = false;

			for (int i = 0; i < size; i++)
			{
				bool collision = doCollision(player, floor[i], player.grounded);
			}
			if (player.controller.requestJump && player.grounded)
				player.rigidbody.impulse.y += 3350;

			if (!player.grounded)
			{
				player.rigidbody.force.y -= 3350;
			}

			player.controller.poll(player.rigidbody, player.transform);
			player.rigidbody.integrate(player.transform, dt);

			player.sprite.draw(player.transform);
			if (getKey('A'))
			{
				player.transform.dim.x = -64.6f;
			}
			if (getKey('D'))
			{
				player.transform.dim.x = 64.6f;
			}
			drawBox(player.collider.getGlobalBox(player.transform), BLUE);
		}



		for (int i = 0; i < size; i++)
		{
			floor[i].sprite.draw(floor[i].transform);
		}

	

		for (int i = 0; i < size; i++)
		{
			drawBox(floor[i].collider.getGlobalBox(floor[i].transform), BLACK);
		}
		//drawBox(wall.collider.getGlobalBox(wall.transform), BLACK);

		for (int i = 0; i < size; i++)
		{
			doCollision(player, floor[i], player.grounded);
			doCollision(enemy, floor[i], enemy.grounded);
		}
		//doCollision(player, wall);
	
		if (enemy.alive == true)
		{
			for (int i = 0; i < size; i++)
			{
				doCollision(enemy, floor[i], enemy.grounded);
			}

			drawBox(enemy.collider.getGlobalBox(enemy.transform), RED);
			enemy.sprite.draw(enemy.transform);
			enemy.update(player);
			enemy.rigidbody.integrate(enemy.transform, dt);
			doCollision(enemy, player);
		}

	}
}