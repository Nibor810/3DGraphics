#include "Scene.h"
#include "stb_image.h"
#include <GL/freeglut.h>

void Scene::drawScene()
{
	for (auto o : gameObjects)
	{
		o->drawGameObject();
	}
}

void Scene::updateScene(float deltaTime)
{
	for (auto o : gameObjects)
	{
		o->updateGameObject(deltaTime);
	}
}

void Scene::addGameObject(GameObject * object)
{
	gameObjects.push_back(object);
}

void Scene::removeGameObject(GameObject * object)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i] == object)
		{
			gameObjects.erase(gameObjects.begin()+i);
		}
	}
}

void Scene::loadMap(const char * imageLocation)
{
	map.raw_collision_map = stbi_load(imageLocation, &map.width, &map.height, &map.bpp, 1);

}

void Scene::drawText(std::string text, int x, int y)
{
	glColor3f(1, 1, 1);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_SMOOTH);
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION); // change the current matrix to PROJECTION
	double matrix[16]; // 16 doubles in stack memory
	glGetDoublev(GL_PROJECTION_MATRIX, matrix); // get the values from PROJECTION matrix to local variable
	glLoadIdentity(); // reset PROJECTION matrix to identity matrix
	glOrtho(0, WINDOW_SIZE_WIDTH, 0, WINDOW_SIZE_HEIGHT, -5, 5); // orthographic perspective
	
	glMatrixMode(GL_MODELVIEW); // change current matrix to MODELVIEW matrix again

	
	glPushMatrix(); // push current state of MODELVIEW matrix to stack
	glLoadIdentity(); // reset it again. (may not be required, but it my convention)
	glRasterPos2i(x, WINDOW_SIZE_HEIGHT - y); // raster position in 2D
	for (int i = 0; i<text.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]); // generation of characters in our text with 9 by 15 GLU font
	}
	glPopMatrix(); // get MODELVIEW matrix value from stack
	glMatrixMode(GL_PROJECTION); // change current matrix mode to PROJECTION
	
	glLoadMatrixd(matrix); // reset
	
	glMatrixMode(GL_MODELVIEW); // change current matrix mode to MODELVIEW
	
	
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_SMOOTH);
}

void Scene::drawHUD()
{
	drawText("temp", WINDOW_SIZE_WIDTH - 100, 25);
	drawText("test", 10, 25);
}

Scene::Scene()
{
}


Scene::~Scene()
{
}
