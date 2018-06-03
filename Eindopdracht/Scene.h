#pragma once
#include <vector>
#include "GameObject.h"
class Scene
{
public:
	std::vector<GameObject*> gameObjects;
	void drawScene();
	void updateScene(float deltaTime);
	void addGameObject(GameObject* object);
	void removeGameObject(GameObject* object);
	Scene();
	~Scene();
};

