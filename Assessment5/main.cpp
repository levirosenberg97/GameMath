#include "sfwdraw.h"
#include "Block.h"
#include "vec2.h"
#include "ScoreBoard.h"

using namespace sfw;

int main()
{
	int size = 9;
	bool firstFrame = true;

	initContext(1280, 720);

	setBackgroundColor(WHITE);
	
	Scoreboard score;
	score.transform.pos = { 1100,710 };
	score.transform.dim = { 30,30 };


	Block floor[9];
	floor[0].transform.pos = vec2{ 640,-100 };
	floor[0].transform.dim = { 1378,343 };
	floor[0].collider.box.extents = { .5,.5 };

	floor[1].transform.pos = vec2{ 0,365 };
	floor[1].transform.dim = { 0,800 };
	floor[1].collider.box.extents = { .5,.5 };
	
	floor[2].transform.pos = vec2{ 1280,365 };
	floor[2].transform.dim = { 0,800 };
	floor[2].collider.box.extents = { .5,.5 };
	
	//Block wall;

	floor[3].transform.pos = vec2{ 740,125 };
	floor[3].transform.dim = { 175,105 };
	floor[3].collider.box.extents = { .5,.5 };

	floor[4].transform.pos = vec2{ 520,270 };
	floor[4].transform.dim = { 175,25 };
	floor[4].collider.box.extents = { .5,.5 };

	floor[5].transform.pos = vec2{ 320,370 };
	floor[5].transform.dim = { 175,25 };
	floor[5].collider.box.extents = { .5,.5 };

	floor[6].transform.pos = vec2{ 480,490 };
	floor[6].transform.dim = { 175,25 };
	floor[6].collider.box.extents = { .5,.5 };

	floor[7].transform.pos = vec2{ 90,460 };
	floor[7].transform.dim = { 175,25 };
	floor[7].collider.box.extents = { .5,.5 };

	floor[8].transform.pos = vec2{ 960,280 };
	floor[8].transform.dim = { 175,25 };
	floor[8].collider.box.extents = { .5,.5 };

	float sizeX = 32.3f;

	Player player;
	player.transform.dim = { sizeX,72.3f };
	player.transform.pos = { 240,60 };
	player.collider.box.extents = { .5,.5 };
	player.sprite = loadTextureMap("Player.png");
	player.alive = true;

	Background back;
	back.transform.pos = { 640,260 };
	back.transform.dim = { 1280,720 };
	back.sprite = loadTextureMap("Background.png"); //loadTextureMap("Backdrop.jpg");

	Enemy enemy[5];
	enemy[0].transform.dim = { 29.5,36.5 };
	enemy[0].transform.pos = { 1100,60 };
	enemy[0].collider.box.extents = { .5,.5 };
	enemy[0].sprite = loadTextureMap("Enemy.png");
	enemy[0].alive = true;
	enemy[0].startX = enemy[0].transform.pos.x;
	enemy[0].startY = enemy[0].transform.pos.y;
	enemy[0].startSpeed = enemy[0].xSpeed;

	enemy[1].transform.dim = { 29.5,36.5 };
	enemy[1].transform.pos = { 90,485 };
	enemy[1].collider.box.extents = { .5,.5 };
	enemy[1].sprite = loadTextureMap("Enemy.png");
	enemy[1].alive = true;
	enemy[1].startX = enemy[1].transform.pos.x;
	enemy[1].startY = enemy[1].transform.pos.y;
	enemy[1].xSpeed = 100;
	enemy[1].startSpeed = enemy[1].xSpeed;

	enemy[2].transform.dim = { 29.5,36.5 };
	enemy[2].transform.pos = { 480,485 };
	enemy[2].collider.box.extents = { .5,.5 };
	enemy[2].sprite = loadTextureMap("Enemy.png");
	enemy[2].alive = true;
	enemy[2].startX = enemy[2].transform.pos.x;
	enemy[2].startY = enemy[2].transform.pos.y;
	enemy[2].xSpeed = -100;
	enemy[2].startSpeed = enemy[2].xSpeed;


	enemy[3].transform.dim = { 29.5,36.5 };
	enemy[3].transform.pos = { 320,375 };
	enemy[3].collider.box.extents = { .5,.5 };
	enemy[3].sprite = loadTextureMap("Enemy.png");
	enemy[3].alive = true;
	enemy[3].startX = enemy[3].transform.pos.x;
	enemy[3].startY = enemy[3].transform.pos.y;
	enemy[3].xSpeed = 100;
	enemy[3].startSpeed = enemy[3].xSpeed;

	enemy[4].transform.dim = { 29.5,36.5 };
	enemy[4].transform.pos = { 920,250 };
	enemy[4].collider.box.extents = { .5,.5 };
	enemy[4].sprite = loadTextureMap("Enemy.png");
	enemy[4].alive = true;
	enemy[4].startX = enemy[4].transform.pos.x;
	enemy[4].startY = enemy[4].transform.pos.y;
	enemy[4].xSpeed = -	100;
	enemy[4].startSpeed = enemy[4].xSpeed;

	for (int i = 0; i < size; i++)
	{
		floor[i].sprite = loadTextureMap("Wall.png");
	}

	while(stepContext())
	{
		float dt = getDeltaTime();

		float timer = dt;

		if (firstFrame)
		{
			firstFrame = false;
			continue;
		}

		back.sprite.draw(back.transform);

		score.draw();

		if (player.alive == true)
		{
			player.grounded = false;

			for (int i = 0; i < size; i++)
			{
				bool collision = doCollision(player, floor[i], player.grounded);
			}
			if (player.controller.requestJump && player.grounded)
				player.rigidbody.impulse.y += 1000;

			if (!player.grounded)
			{
				player.rigidbody.force.y -= 1500;
			}

			player.controller.poll(player.rigidbody, player.transform);
			player.rigidbody.integrate(player.transform, dt);

			player.sprite.draw(player.transform);
			if (getKey('A'))
			{
				player.transform.dim.x = -sizeX;
			}
			if (getKey('D'))
			{
				player.transform.dim.x = sizeX;
			}
			//drawBox(player.collider.getGlobalBox(player.transform), BLUE);
		}
		else
		{
			drawString(loadTextureMap("fontmap.png", 16, 16), "GAME OVER", 440, 360, 50, 50, 0, 000, RED);
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
			for (int j = 0; j < 5; j++)
			{
				doCollision(enemy[j], floor[i], enemy[j].grounded);
			}
		}
		//doCollision(player, wall);
		for (int i = 0; i < 5; i++)
		{
			if (enemy[i].alive == true)
			{
				enemy[i].grounded = false;

				for (int j = 0; j < size; j++)
				{
					doCollision(enemy[i], floor[j], enemy[i].grounded);
				}

				if (!enemy[i].grounded)
				{
					enemy[i].rigidbody.force.y -= 1500;
				}

				//drawBox(enemy.collider.getGlobalBox(enemy.transform), RED);
				enemy[i].sprite.draw(enemy[i].transform);
				enemy[i].update(player);
				enemy[i].rigidbody.integrate(enemy[i].transform, dt);

			}
			else
			{
				enemy[i].currentTimer += dt;
				
				if (enemy[i].alive == false && enemy[i].currentTimer >= enemy[i].respawnTimer)
				{
					enemy[i].rigidbody.velocity = { 0,0 };
					enemy[i].rigidbody.force = { 0,0 };
					
					enemy[i].currentTimer = 0;
					enemy[i].alive = true;
					enemy[i].transform.pos.x = enemy[i].startX;
					enemy[i].transform.pos.y = enemy[i].startY;
					enemy[i].xSpeed = enemy[i].startSpeed;

				}
			}


			if (enemy[i].alive && player.alive)
			{
				doCollision(enemy[i], player,score);
			}
		}
	}
}