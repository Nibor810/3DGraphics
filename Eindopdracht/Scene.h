#pragma once
#include <vector>
#include "GameObject.h"
#include "GameObject.h"
#include "CubeDrawComponent.h"
#include "ModelComponent.h"
#include "Skybox.h"
#define WINDOW_SIZE_WIDTH 800
#define WINDOW_SIZE_HEIGHT 600
#define SKYBOX_MIN 500
#define PI 3.14159265358979323846f
class Scene
{
public:
	struct Map
	{
		unsigned char* raw_collision_map;
		int width, height, bpp;
		float scale;
	} map;
	Skybox skybox;
	std::vector<GameObject*> gameObjects;
	void drawScene();
	void updateScene(float deltaTime);
	void addGameObject(GameObject* object);
	void removeGameObject(GameObject* object);
	void loadMap(const char* imageLocation, GLuint* textures);
	void drawText(std::string text, int x, int y);
	void drawHUD();
	Vector3D map_point_to_world_point(const Vector3D& point) const;


	Scene();
	~Scene();
};

