#include "sfwdraw.h"
#include"vec2.h"
#include "Player.h"
#include "Transform.h"
#include <cmath>

int main()
{
	sfw::initContext(1280,600);

	Transform myTransform;
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

	//Player me;
	//me.pos = { 400,300 };
	//me.speed = 5;
	//me.teleTime = 10.0f;
	//me.maxTime = 10;
	//me.maxtele = 10;

	while (sfw::stepContext())
	{
		float t = sfw::getTime();

		myTransform.angle += sfw::getDeltaTime() + 900;
		myTransform.dim = vec2{ sinf(t) + 2, sinf(t) + 2 };
		DrawMatrix(myTransform.getLocalTransform(), 40);

		DrawMatrix(myBaby.getGlobalTransform(), 30);
		DrawMatrix(myBaby2.getGlobalTransform(), 30);
		DrawMatrix(myBaby3.getGlobalTransform(), 20);
		DrawMatrix(myBaby4.getGlobalTransform(), 20);


	}

	sfw::termContext();

}