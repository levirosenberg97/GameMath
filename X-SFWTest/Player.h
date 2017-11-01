#pragma once

#include "sfwdraw.h"
#include "vec2.h"
#include "Sprite.h"
#include "Controller.h"
#include "Collider.h"


class Player
{		
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Controller controller;
	Sprite sprite;
};