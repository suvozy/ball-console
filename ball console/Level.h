#pragma once

#include <GL/glew.h>
#include <GL/glut.h>
#include <algorithm>
#include <list>
#include "cstdlib"
#include <time.h>
#include "Vector2.h"
#include "InputState.h"
#include "Rectangle.h"
#include "Ball.h"

using namespace std;

class Level
{
	bool isGameOver;

	static const int gap = 160, minPlat = 200, maxPlat = 1500, heightVari = 50;
	static const int maxTrapSize = 160, trapsMul = 40;

	list<Rectangle> platforms;
	list<Rectangle> traps;
	int lastGen;

	Ball ball;
	float cameraPosX, levelGen;

	void drawPlatforms();

public:
	Level(void);
	~Level(void);

	bool IsGameOver() { return isGameOver; }

	void update(InputState);
	void draw();
};
