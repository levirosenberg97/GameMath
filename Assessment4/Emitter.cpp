#include "Emitter.h"
#include"Particles.h"
#include"sfwdraw.h"
#include"Player.h"

using namespace sfw;

Emitter::Emitter()
{
	for (int i = 0; i < 1; i++)
	{
		particles[i].enabled = false;
	}

	spawnAcc = 0.0f;
}

void Emitter::update(Player object)
{
	// check if time to spawn new particle
	//if so create one
	
	if (object.enabled == true)
	{

		if (getMouseButton(0))
		{
			// look for an unused particle
			for (int i = 0; i < 1; i++)
			{
				if (particles[i].enabled == false)
				{
					//reactivate it
					BaseParticles& baby = particles[i];

					baby.myTrans.pos = vec2{ object.myTrans.pos.x, object.myTrans.pos.y };

					baby.Dir = nrm(vec2{ sfw::getMouseX(),sfw::getMouseY() } -baby.myTrans.pos);
					baby.speed = 50;



					baby.enabled = true;
					spawnAcc = 0.0f;
					break;
				}
			}
		}

		//update all of the particles that are active
		for (int i = 0; i < 1; i++)
		{
			if (particles[i].enabled == true)
			{
				particles[i].update();
				if (particles[i].myTrans.pos.x > 1280 || particles[i].myTrans.pos.x < 0 || particles[i].myTrans.pos.y > 600 || particles[i].myTrans.pos.y < 0)
				{
					particles[i].enabled = false;
				}
			}
		}
	}
	for (int i = 0; i < 1; i++)
	{
		if (object.enabled == false)
		{
			particles[i].enabled = false;
		}
	}
}

void Emitter::draw(Player object)
{
	for (int i = 0; i < 1; i++)
	{
		// only draw active particles
		if (particles[i].enabled)
		{
			particles[i].draw(object);
		}
	}
}
