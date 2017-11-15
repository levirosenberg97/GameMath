#include "ScoreBoard.h"
#include<iostream>
#include "sfwdraw.h"
#include <string>

using namespace std;
using namespace sfw;

void Scoreboard::draw()
{
	string scoreText = to_string(score);

	drawString(loadTextureMap("fontmap.png", 16, 16), scoreText.c_str(), transform.pos.x, transform.pos.y, transform.dim.x, transform.dim.y, 0, 000, BLACK);
}
