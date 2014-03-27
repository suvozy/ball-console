#pragma once

#include <list>
#include <math.h>
#include "Rectangle.h"
#include "InputState.h"
using namespace std;

class Ball
{
	Vector2 pos, speed;
	float maxSpeedTime, speedTime;
	bool isOnGround;

	float jumpTime, maxJumpTime;

public:
	Ball(Vector2 pos = Vector2());
	~Ball(void);

	Rectangle getBallRect();
	void update(InputState, list<Rectangle>);
	void draw();
};
