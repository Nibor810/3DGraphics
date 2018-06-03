#include "Scene.h"



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

Scene::Scene()
{
}


Scene::~Scene()
{
}
