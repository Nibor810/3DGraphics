#pragma once
#include "DrawComponent.h"
class TreeComponent : public DrawComponent
{
public:
	int textureID;
	virtual void draw();
	TreeComponent();
	~TreeComponent();
};

