// ball console.cpp : Defines the entry point for the console application.
//

//#pragma comment (lib, "opengl32.lib")
//#pragma comment (lib, "glut32.lib")

#include "stdafx.h"
#include <GL/glew.h>  
#include <GL/glut.h>
#include <string.h>
#include "Level.h"
#include "GameTime.h"
#include "InputState.h"

CGameTime gameTime;
InputState inputSate;
Level level;

void keyPressed(unsigned char key, int x, int y)
{ inputSate.lastKeySates[key] = inputSate.currentKeyStates[key]; inputSate.currentKeyStates[key] = true; }

void keyUp(unsigned char key, int x, int y)
{ inputSate.lastKeySates[key] = inputSate.currentKeyStates[key]; inputSate.currentKeyStates[key] = false; }

int elapsedTime = 0;
void *font = GLUT_BITMAP_9_BY_15;
void output(int x, int y, string s)
{
  glRasterPos2f(x, y);
  for (int i = 0; i < (int)s.length(); i++) 
	  glutBitmapCharacter(font, s[i]);
}

void update()
{
	if(!level.IsGameOver())
	{
		elapsedTime = glutGet(GLUT_ELAPSED_TIME);
		level.update(inputSate);
	}

	glutPostRedisplay();
}

void display()
{
	glClearColor(.6f, .6f, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	char buffer [9999];
	string s = itoa(elapsedTime / 1000, buffer, 10);
	output(550, 550, "Score = ");	output(620, 550, s);

	level.draw();

	glFlush();
}

void reshape(int width, int height)
{
	width = 800, height = 600;
	glutReshapeWindow(width, height);

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, 0.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);
	glutCreateWindow("First Window");

	glutDisplayFunc(display);
	glutIdleFunc(update);

	glutReshapeFunc(reshape);

	glEnable (GL_TEXTURE_2D);

	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);

	glutMainLoop();
}