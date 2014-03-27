#include "StdAfx.h"
#include "Ball.h"

Ball::Ball(Vector2 pos) : pos(pos) 
{
	speed = Vector2::Zero;

	jumpTime = 0, maxJumpTime = 18.0f;
	maxSpeedTime = 120, speedTime = 0;
}

Ball::~Ball(void) { }

Rectangle Ball::getBallRect()
{
	return Rectangle(pos.X, pos.Y, 20, 20);
}

void Ball::update(InputState inputSate, list<Rectangle> platforms)
{
	speed.Y -= 0.002f;

	speedTime = min(speedTime + 1, maxSpeedTime);
	speed.X = 1.2f * sin(speedTime / maxSpeedTime * 3.14f / 4);

	//if(inputSate.currentKeyStates[(int)'a']) pos.X -= .2f;
	//if(inputSate.currentKeyStates[(int)'d']) pos.X += .2f;

	if(isOnGround && inputSate.IsSelect()) jumpTime = maxJumpTime;

	if(jumpTime > 0)
	{
		jumpTime = max(jumpTime - 1, 0.0f);
		speed.Y += 0.04f;
	}

	pos += speed;

	isOnGround = false;
	for(list<Rectangle>::iterator  i = platforms.begin(); i != platforms.end(); i++)
	{
		Vector2 intersectionDepth = getBallRect().GetIntersectionDepth(*i);

		if(intersectionDepth != Vector2())
		{
			if(abs(intersectionDepth.Y) < abs(intersectionDepth.X))
			{
				pos.Y += intersectionDepth.Y;
				speed.Y = 0;
				if(intersectionDepth.Y > 0) isOnGround = true;
			}
			else
			{
				pos.X += intersectionDepth.X;
				speed.X = 0; speedTime = 0;
			}
		}
	}
}

void Ball::draw()
{
	Rectangle rect = getBallRect();

	glRectf(rect.x, rect.y, rect.x + rect.width, rect.y + rect.height);
}
