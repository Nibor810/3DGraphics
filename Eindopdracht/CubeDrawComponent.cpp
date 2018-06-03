#include "CubeDrawComponent.h"
#include <GL/freeglut.h>



void CubeDrawComponent::setSize(float size_)
{
	size = size_;
}

void CubeDrawComponent::setColor(float r, float g, float b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void CubeDrawComponent::draw()
{
	glBegin(GL_QUADS);
	glColor3f(color[0],color[1],color[2]);
	glVertex3f(-size, -size, -size);
	glVertex3f(size, -size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(-size, size, -size);

	glVertex3f(-size, -size, size);
	glVertex3f(size, -size, size);
	glVertex3f(size, size, size);
	glVertex3f(-size, size, size);

	glVertex3f(-size, -size, -size);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, size, size);
	glVertex3f(-size, -size, size);

	glVertex3f(size, -size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, size, size);
	glVertex3f(size, -size, size);

	glVertex3f(-size, -size, -size);
	glVertex3f(size, -size, -size);
	glVertex3f(size, -size, size);
	glVertex3f(-size, -size, size);

	glVertex3f(-size, size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, size, size);
	glVertex3f(-size, size, size);
	glEnd();
}

CubeDrawComponent::CubeDrawComponent()
{
}

CubeDrawComponent::~CubeDrawComponent()
{
}
