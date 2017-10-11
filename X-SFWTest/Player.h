#pragma once

#include "sfwdraw.h"
#include "vec2.h"

class Player
{		
public:
	vec2 pos;
	
	
	float maxTime;
	float time = maxTime;
	float maxtele;
	float teleTime = maxtele;
	float speed;
	void update();
	void draw();
};