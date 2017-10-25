#include "Baby.h"


Babys::Babys(Transform &trans, float posX, float posY, float dimX, float dimY, float ang)
{
	lilT.pos = vec2{ posX,posY };
	lilT.dim = vec2{ dimX,dimY };
	lilT.angle = ang;
	lilT.e_parent = &trans;
}

void Babys::update(Player &ply, Emitter &pea, Spawner &eme, float rad)
{
	if (dist(ply.myTrans.pos, lilT.getGlobalPosition()) < (ply.radius + rad) && enabled == true)
	{
		ply.enabled = false;
	}
	for (int i = 0; i < 1; i++)
	{
		if (rad == 8 && enabled == true && dist(pea.particles[i].myTrans.pos,lilT.getGlobalPosition()) < (pea.particles[i].r + rad) && pea.particles[i].enabled == true)
		{
			enabled = false;
			pea.particles[i].enabled = false;
		}

		if (rad == 15 && enabled == true && dist(pea.particles[i].myTrans.pos, lilT.getGlobalPosition()) < (pea.particles[i].r + rad) && pea.particles[i].enabled == true)
		{
			pea.particles[i].enabled = false;
			enabled = false;
		}
	}

}

void Babys::draw(float rad)
{
	if (enabled == true)
	{
		DrawMatrix(lilT.getGlobalTransform(), rad);
	}
}
