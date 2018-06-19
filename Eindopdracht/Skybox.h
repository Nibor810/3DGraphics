#pragma once

#include <windows.h>
#include <GL/gl.h>
#include <math.h>

class Skybox
{
public:
	Skybox();
	~Skybox();
	void load(float zfar, int tex_id);
	void draw(float x, float y, float z) const;

private:
	int id_Skybox;
	int texture_Skybox;
};