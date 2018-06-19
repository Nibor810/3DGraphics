#include "PlaneComponent.h"
#include <GL/freeglut.h>


void PlaneComponent::setColor(float r, float g, float b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void PlaneComponent::setSize(float size_)
{
	size = size_;
}

void PlaneComponent::draw()
{
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_QUADS);
	glVertex3f(-size, 0, -size);
	glVertex3f(size, 0, -size);
	glVertex3f(size, 0, size);
	glVertex3f(-size, 0, size);
	glEnd();
}

PlaneComponent::PlaneComponent()
{
}


PlaneComponent::~PlaneComponent()
{
}
