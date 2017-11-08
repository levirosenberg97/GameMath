#include "sfwdraw.h"
#include"vec2.h"
#include "Player.h"
#include "Transform.h"
#include <cmath>
#include"Rigidbody.h"
#include"DrawShape.h"
#include "Collision.h"
#include "Collider.h"

int main()
{
	sfw::initContext(1280,600);

	Player player;

	player.sprite = sfw::loadTextureMap("redRocket.png");
	player.transform.dim = vec2{ 48,48 };
	player.transform.pos = vec2{ 400,300 };
	player.collider.box.extents = { .5,.5 };

	Wall wall[2];

	wall[0].transform.pos = {640,50 };
	wall[0].transform.dim = { 1280,240 };
	wall[0].collider.box.extents = { .5,.5 };
	wall[0].sprite = sfw::loadTextureMap("bricks.png");

	wall[1].transform.pos = { 640,550 };
	wall[1].transform.dim = { 1280,240 };
	wall[1].collider.box.extents = { .5,.5 };
	wall[1].sprite = sfw::loadTextureMap("bricks.png");

	Ball ball;
	ball.transform.pos = { 540,300 };
	ball.sprite.handle;
	ball.transform.dim = { 32,32 };
	ball.collider.box.extents = { .5,.5 };
	ball.rigidbody.velocity = { 0,-100 };
	ball.rigidbody.drag = 0;


	Rigidbody rigidbody;
	Transform transform;

	circle circ = { {0,0},50 };
	
	


	

	/*Transform myTransform;
	myTransform.pos = vec2{ 300,400 };
	myTransform.dim = vec2{ 2,2 };
	myTransform.angle = 0;

	Transform myBaby;
	myBaby.pos = vec2{10,10 };
	myBaby.dim = vec2{ 1,1 };
	myBaby.angle = 180;
	myBaby.e_parent = &myTransform;

	Transform myBaby2;
	myBaby2.pos = vec2{ 10,-10 };
	myBaby2.dim = vec2{ 1,1 };
	myBaby2.angle = 90;
	myBaby2.e_parent = &myTransform;

	Transform myBaby3;
	myBaby3.pos = vec2{ 20,-20 };
	myBaby3.dim = vec2{ 1,1 };
	myBaby3.angle = 90;
	myBaby3.e_parent = &myTransform;

	Transform myBaby4;
	myBaby4.pos = vec2{ 20,20 };
	myBaby4.dim = vec2{ 1,1 };
	myBaby4.angle = 180;
	myBaby4.e_parent = &myTransform;
*/
	//Player me;
	//me.pos = { 400,300 };
	//me.speed = 5;
	//me.teleTime = 10.0f;
	//me.maxTime = 10;
	//me.maxtele = 10;

	while (sfw::stepContext())
	{
	/*	float t = sfw::getTime();

		myTransform.angle += sfw::getDeltaTime() + 90;
		myTransform.dim = vec2{ sinf(t) + 2, sinf(t) + 2 };
		DrawMatrix(myTransform.getLocalTransform(), 40);

		DrawMatrix(myBaby.getGlobalTransform(), 30);
		DrawMatrix(myBaby2.getGlobalTransform(), 30);
		DrawMatrix(myBaby3.getGlobalTransform(), 20);
		DrawMatrix(myBaby4.getGlobalTransform(), 20);*/

		float dt = sfw::getDeltaTime();

		player.controller.poll(player.rigidbody, player.transform);
		player.rigidbody.integrate(player.transform, dt);
		player.sprite.draw(player.transform);

		for (int i = 0; i < 2; i++)
		{
			wall[i].sprite.draw(wall[i].transform);
		}
		ball.rigidbody.integrate(ball.transform, dt);


		drawRect(player.collider.getGlobalBox(player.transform), BLUE);
		drawRect(ball.collider.getGlobalBox(ball.transform), RED);
		
		for (int i = 0; i < 2; i++)
		{
			drawRect(wall[i].collider.getGlobalBox(wall[i].transform), WHITE);
		}

		for (int i = 0; i < 2; i++)
		{
			doCollision(player, wall[i]);
			doCollision(ball, wall[i]);
		}
		doCollision(player, ball);


		//unsigned color = result.penDepth < 0 ? WHITE : RED;
		////drawRect(box2, color);
		////drawRect(transform.getGlobalTransform() * AARP,GREEN);
		//drawCircle(transform.getGlobalTransform() * circ);
		//DrawMatrix(transform.getGlobalTransform(),1);
		//drawCircle(circ2);
		//
		//
		//player.rigidbody.force += { 0,-25 };
		//player.rigidbody.integrate(transform, dt);
		//DrawMatrix(transform.getGlobalTransform(), 50);

	}

	sfw::termContext();

}