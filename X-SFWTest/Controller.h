#pragma once
#include "Transform.h"
#include "Rigidbody.h"
#include "sfwdraw.h"

class Controller
{

public:
	void poll(Rigidbody &rb, const Transform &t)
	{
		if (sfw::getKey('W'))
		{
			rb.force += t.getGlobalTransform()[1].xy * 10;
		}
		if (sfw::getKey('D'))
		{
			rb.torque += -360;
		}
		if (sfw::getKey('A'))
		{
			rb.torque += 360;
		}	
		if (sfw::getKey('Q')) 
		{
			rb.impulse += t.getGlobalTransform()[1].xy * 1;
		}
		if (sfw::getKey(' '))
		{
			rb.force += -rb.velocity * 20;
			rb.torque += -rb.angularVelocity * 20;
		}

	}
};