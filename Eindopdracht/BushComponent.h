#pragma once
#include "DrawComponent.h"
class BushComponent : public DrawComponent
{
public:
	int textureID;
	virtual void draw();
	BushComponent();
	~BushComponent();
};

