#pragma once
#include "DrawComponent.h"
class PlaneComponent : public DrawComponent
{
public:
	float size = 1.0f;
	float color[3];
	bool texture = false;
	int textureID;
	void setTexture(int textureID_);
	void setSize(float size);
	void setColor(float r, float g, float b);
	void draw();
	PlaneComponent();
	~PlaneComponent();
};

