#pragma once
#include"Transform.h"
#include "vec2.h"

class Rigidbody
{
public:
	float mass;



	vec2 velocity,   // speed * direction
		acceleration,
		force,
		impulse;     // continuous force

	float drag;
	// the sum of all forces applied to an object

	//A = F/M
	//F = MA

	float angularVelocity;
	float angularAcceleration;
	float torque;
	float angularDrag;

	Rigidbody() : velocity{ 0,0 },
		acceleration{ 0,0 },
		force{ 0,0 },
		impulse{ 0,0 },
		mass(1),
		drag(.25f),
		angularVelocity(0),
		angularAcceleration(0),
		torque(0),
		angularDrag(.25f)
	{

	}


	void integrate(Transform &T, float dt)
	{
		//linear motion
		acceleration = force / mass;
		velocity += acceleration * dt + impulse / mass;
		T.pos += velocity * dt;
		impulse = { 0,0 };
		force.x = -velocity.x * drag;
		force.y = -velocity.y * drag;

		//angular motion(sort of)
		angularAcceleration = torque / mass;
		angularVelocity += angularAcceleration * dt;
		T.angle += angularVelocity * dt;

		torque = -angularVelocity * angularDrag;
	}
};