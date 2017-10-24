#pragma once
#include "Particles.h"
#include "Player.h"

class Emitter
{
	//Time since last Spawned Particle
	float spawnAcc;

public:

	Emitter();

	//collection of Particles
	BaseParticles particles[100];

	//current particle id
	int particleId;

	//Time Between Spawn
	float spawnInt;

	void update(Player Object);
	void draw(Player object);

};