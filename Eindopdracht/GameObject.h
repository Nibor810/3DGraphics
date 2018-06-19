#pragma once
#include "Vector3D.h"
#include "DrawComponent.h"
#include "Component.h"
#include <vector>
class GameObject
{
public:
	DrawComponent* drawComponent;
	std::vector<Component*> components;
	Vector3D* position;
	Vector3D* rotation;
	Vector3D* scale;
	Vector3D* offset;
	void setScale(float x, float y, float z);
	void setScaleAll(float scale);
	void setRotation(float x, float y, float z);
	void setRotationAll(float rotation);
	void setPosition(float x, float y, float z);
	void setOffset(float x, float y, float z);
	void drawGameObject();
	void updateGameObject(float deltaTime);
	void addComponent(Component* comp);
	GameObject();
	~GameObject();
};

