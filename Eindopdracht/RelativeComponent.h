#pragma once
#include "Component.h"
class GameObject;
class RelativeComponent : public Component
{
public:
	GameObject * centerObject;
	virtual void update(float elapsedTime);
	RelativeComponent();
	~RelativeComponent();
};

