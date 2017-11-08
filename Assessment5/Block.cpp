#include "Block.h"

using namespace sfw;

bool doCollision(Player & player, const Block & block)
{
	auto hit = collides(player.transform, player.collider, block.transform, block.collider);

	if (hit.penDepth >= 0)
	{
		static_resolution(player.transform.pos, player.rigidbody.velocity, hit, 0);
		return true;
	}
	return false;
}

void drawBox(const AABB & C, int color)
{
	float x1 = C.position.x + C.extents.x;
	float x2 = C.position.x - C.extents.x;
	float y1 = C.position.y + C.extents.y;
	float y2 = C.position.y - C.extents.y;

	//Top
	sfw::drawLine(x2, y1, x1, y1, color);
	//Bottom
	sfw::drawLine(x2, y2, x1, y2, color);
	//Left
	sfw::drawLine(x2, y2, x2, y1, color);
	//Right
	sfw::drawLine(x1, y2, x1, y1, color);
}
