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
	myTransform.dim = vec2{ 1,1 };


	//Player me;
	//me.pos = { 400,300 };
	//me.speed = 5;
	//me.teleTime = 10.0f;
	//me.maxTime = 10;
	//me.maxtele = 10;

	while (sfw::stepContext())
	{
		float t = sfw::getTime();

		myTransform.angle += 125*sfw::getDeltaTime();
		myTransform.dim = vec2{ sinf(t) + 2, sinf(t) + 2 };
		DrawMatrix(myTransform.getLocalTransform(), 40);

	}

	sfw::termContext();

}