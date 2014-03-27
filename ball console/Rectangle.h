#pragma once

#include "utility"
#include "math.h"
#include "Vector2.h"
#include "GL/glew.h"
#include "GL/glut.h"
using namespace std;

class Rectangle
{
public:
	float x, y, width, height;

	Rectangle(void)
	{
		x = y = width = height = 0;
	}

	Rectangle(float x, float y, float width, float height)
	{
		this->x = x; this->y = y; this->width = width; this->height = height;
	}

	~Rectangle(void);

	Vector2 GetIntersectionDepth(Rectangle);
	Vector2 GetBottomCenter();
	Vector2 Center() { return Vector2(x + width / 2, y + height / 2); }

	bool Contains(Vector2);
	bool Intersect(Rectangle);
};
