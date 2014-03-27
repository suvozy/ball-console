#include "StdAfx.h"
#include "Level.h"

Level::Level(void)
{
	cameraPosX = 0;
	lastGen = 0;

	ball = Ball(Vector2(100, 500));
	platforms.push_back(Rectangle(0, 0, 600, 300));
	levelGen += 600;

	//platforms.push_back(Rectangle(500, 150, 400, 50));
	//traps.push_back(Rectangle(600, 100, trapsMul * 4, 20));
	srand(time(NULL));
}

Level::~Level(void) { }

void Level::update(InputState inputSate)
{	
	ball.update(inputSate, platforms);

	Vector2 ballPos = ball.getBallRect().Center();

	while(levelGen < cameraPosX + 800 + 20)
	{
		lastGen = lastGen == 0 ? 1 : rand() %2;

		if(lastGen)
		{
			int w = minPlat + rand() % (maxPlat - minPlat);
			int h = (rand() % (heightVari * 2)) - heightVari, h2 = platforms.front().height;

			if(h + h2 < 150 || h + h2 > 450) h = -h;
			h += h2;

			platforms.push_back(Rectangle(levelGen, 0, w, h));
			
			if(w > 500)
			{
				int a = rand() % 2 + (w > 1000 ? 1 : 0);
				for(int i = 1; i <= a; i++)
				{
					int wt = (rand() % maxTrapSize) / trapsMul;
					if(wt == 0) wt = 1;
					wt *= trapsMul;
					traps.push_back(Rectangle(levelGen + (i * (w / (a + 1))) - (wt / 2), h,  wt, 20));
				}
			}

			levelGen += w;
		}
		else levelGen += gap;
	}

	while(platforms.size() > 1 && platforms.front().x + platforms.front().width < cameraPosX)
			platforms.pop_front();

	while(!traps.empty() && traps.front().x + traps.front().width < cameraPosX)
			traps.pop_front();

	for(list<Rectangle>::iterator  i = traps.begin(); i != traps.end(); i++)
		if((*i).Intersect(ball.getBallRect())) isGameOver = true;

	if(ballPos.Y < 0) isGameOver = true;

	float d = (ballPos.X - cameraPosX) - 250;
	if(d > 0) cameraPosX += d;
}

void Level::draw()
{
	gluLookAt(cameraPosX, 0, 1, cameraPosX, 0, 0, 0, 1, 0);

	if(isGameOver) glColor3f(1, 0, 0);
	ball.draw();

	if(isGameOver) glColor3f(1, 1, 1);
	drawPlatforms();
}

void Level::drawPlatforms()
{
	for(list<Rectangle>::iterator  i = platforms.begin(); i != platforms.end(); i++)
	{
		glBegin(GL_LINE_LOOP);
		glVertex2f((*i).x, (*i).y);
		glVertex2f((*i).x, (*i).y + (*i).height);
		glVertex2f((*i).x + (*i).width, (*i).y + (*i).height);
		glVertex2f((*i).x + (*i).width, (*i).y);	
		glEnd();
	}

	for(list<Rectangle>::iterator  i = traps.begin(); i != traps.end(); i++)
	{
		int j = trapsMul / 4;
		Rectangle r = (*i);
		glBegin(GL_LINE_LOOP);
		glVertex2f(r.x, r.y);
		for(int i = 0; i <= r.width; i += j)
			if(i % j == 0 && i % (2 * j) == 0) glVertex2f(r.x + i, r.y + r.height);
			else glVertex2f(r.x + i, r.y);
		glVertex2f(r.x + r.width, r.y);
		glEnd();
	}
}