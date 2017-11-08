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
	
	floor[2].transform.pos = vec2{ 640,1180 };
	floor[2].transform.dim = { 1378,343 };
	floor[2].collider.box.extents = { .5,.5 };




	Player player;
	player.transform.dim = { 12.125,27.125 };
	player.transform.pos = { 640,60 };
	player.collider.box.extents = { .5,.5 };
	player.sprite = loadTextureMap("Player.png");
	for (int i = 0; i < size; i++)
	{
		floor[i].sprite = loadTextureMap("Wall.png");
	}

	while(stepContext())
	{
		float dt = getDeltaTime();

		player.grounded = false;
		
		for (int i = 0; i < size; i++)
		{
			bool collision = doCollision(player, floor[i]);
			if (collision) player.grounded = true;
		}
		if (player.controller.requestJump && player.grounded)
			player.rigidbody.velocity.y += 650;

		if (!player.grounded)
		{
			player.rigidbody.force.y -= 650;
		}
		player.controller.poll(player.rigidbody, player.transform);
		player.rigidbody.integrate(player.transform, dt);

		player.sprite.draw(player.transform);

		for (int i = 0; i < size; i++)
		{
			floor[i].sprite.draw(floor[i].transform);
		}

		if (getKey('A'))
		{
			player.transform.dim = { -12.125,27.125 };
		}
		if (getKey('D'))
		{
			player.transform.dim = { 12.125,27.125 };
		}

		drawBox(player.collider.getGlobalBox(player.transform), BLUE);
		for (int i = 0; i < size; i++)
		{
			drawBox(floor[i].collider.getGlobalBox(floor[i].transform), BLACK);
		}
		//drawBox(wall.collider.getGlobalBox(wall.transform), BLACK);

		for (int i = 0; i < size; i++)
		{
			doCollision(player, floor[i]);
		}
		//doCollision(player, wall);
	
	}
}