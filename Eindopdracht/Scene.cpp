#include "Scene.h"
#include "stb_image.h"
#include <GL/freeglut.h>
#include "TreeComponent.h"
#include "BushComponent.h"

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

Vector3D Scene::map_point_to_world_point(const Vector3D& point) const
{
	return Vector3D(point.x - map.width / 2.0f, point.y, point.z - map.height / 2.0f);
}

void Scene::loadMap(const char * imageLocation, GLuint* textures)
{
	map.raw_collision_map = stbi_load(imageLocation, &map.width, &map.height, &map.bpp, 1);
	for (int h = 0; h < map.height; h++) {
		for (int w = 0; w < map.width; w++) {
			//pixelwaarde tussen 40 & 60
			if (map.raw_collision_map[(w + h * map.width)] >= 0 && map.raw_collision_map[(w + h * map.width)] < 100)
			{
				Vector3D position = map_point_to_world_point(Vector3D(w, -1, h));
				//voeg boompje toe
				GameObject* tree = new GameObject();
				TreeComponent* treeComponent = new TreeComponent();
				treeComponent->textureID = textures[3];
				tree->drawComponent = treeComponent;
				tree->setPosition(position.x,position.y, position.z);
				tree->setRotationAll(0);
				tree->setScaleAll(1);
				tree->setOffset(0, 0, 0);
				tree->setOffsetRotationAll(0);
				addGameObject(tree);
			}
			//pixelwaarde tusse 60 & 80
			else if (map.raw_collision_map[(w + h * map.width)] >= 100 && map.raw_collision_map[(w + h * map.width)] < 150)
			{
				//voegbosje toe
				Vector3D position = map_point_to_world_point(Vector3D(w, -1, h));
				//voeg boompje toe
				GameObject* tree = new GameObject();
				BushComponent* bushComponent = new BushComponent();
				bushComponent->textureID = textures[4];
				tree->drawComponent = bushComponent;
				tree->setPosition(position.x, position.y, position.z);
				tree->setRotationAll(0);
				tree->setScaleAll(2);
				tree->setOffset(0, 0, 0);
				tree->setOffsetRotationAll(0);
				addGameObject(tree);
			}
		}
	}
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
	drawText("HUD", WINDOW_SIZE_WIDTH - 100, 25);
	drawText("Dit zou een score kunnen zijn", 10, 25);
}

Scene::Scene()
{
}


Scene::~Scene()
{
}
