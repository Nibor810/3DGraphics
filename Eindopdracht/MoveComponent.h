#pragma once
#include "Component.h"
#include "GameObject.h"
class MoveComponent : public Component
{
public:
	virtual void update(float elapsedTime);
	MoveComponent();
	~MoveComponent();
};

