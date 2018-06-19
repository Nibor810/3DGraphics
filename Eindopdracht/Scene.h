#pragma once
#include <vector>
#include "GameObject.h"
#include "GameObject.h"
#include "CubeDrawComponent.h"
#include "ModelComponent.h"
#include "Skybox.h"
#define WINDOW_SIZE_WIDTH 800
#define WINDOW_SIZE_HEIGHT 600
#define NUMBER_OF_TEXTURES 3
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
	GLuint textures[NUMBER_OF_TEXTURES];
	std::vector<GameObject*> gameObjects;
	void drawScene();
	void updateScene(float deltaTime);
	void addGameObject(GameObject* object);
	void removeGameObject(GameObject* object);
	void loadMap(const char* imageLocation);
	void drawText(std::string text, int x, int y);
	void drawHUD();
	void initWorld();
	void initTextures();
	void loadTexture(int id, const char* location);
	void initScene();
	void initSkybox();
	void initLighting();


	Scene();
	~Scene();
};

