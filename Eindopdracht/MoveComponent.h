#pragma once
#include "Component.h"
class MoveComponent : public Component
{
public:
	float xRotationSpeed;
	float yRotationSpeed;
	float zRotationSpeed;
	void setRotationSpeed(float x, float y, float z);
	virtual void update(float elapsedTime);
	MoveComponent();
	~MoveComponent();
};

