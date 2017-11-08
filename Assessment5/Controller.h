#pragma once
#include "Transform.h"
#include "Rigidbody.h"
#include "sfwdraw.h"

class Controller
{
public:
	bool requestJump;

	void poll(Rigidbody &rb, const Transform &t)
	{
		requestJump = false;
		float dt = sfw::getDeltaTime();

		if (sfw::getKey('W'))
		{
			requestJump = true;
			//rb.drag = 2.f;
			//counter -= dt;
		}
		if (sfw::getKey('D'))
		{
			//rb.torque += -360;
			rb.force.x += 1400;
		}
		if (sfw::getKey('A'))
		{
			//rb.torque += 360;
			rb.force.x -= 1400;
		}
		/*if (sfw::getKey('Q'))
		{
			rb.impulse += t.getGlobalTransform()[1].xy * 1;
		}
		if (sfw::getKey(' '))
		{
			rb.force += -rb.velocity * 20;
			rb.torque += -rb.angularVelocity * 20;
		}*/

	
	}
};