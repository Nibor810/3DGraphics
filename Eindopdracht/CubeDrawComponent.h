#pragma once
#include "DrawComponent.h"
class CubeDrawComponent :
	public DrawComponent
{
public:
	float size = 1.0f;
	float color[3];
	void setSize(float size);
	void setColor(float r, float g, float b);
	void draw();
	CubeDrawComponent();
	~CubeDrawComponent();
};

