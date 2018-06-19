#include "PlaneComponent.h"
#include <GL/freeglut.h>


void PlaneComponent::setColor(float r, float g, float b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void PlaneComponent::setTexture(int textureID_)
{
	texture = true;
	textureID = textureID_;
}

void PlaneComponent::setSize(float size_)
{
	size = size_;
}

void PlaneComponent::draw()
{
	if(texture) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0);		glVertex3f(-size, 0, -size);
		glTexCoord2d(0, 1);		glVertex3f(-size, 0, size);
		glTexCoord2d(1, 1);		glVertex3f(size, 0, size);
		glTexCoord2d(1, 0);		glVertex3f(size, 0, -size);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else {
		glColor3f(color[0], color[1], color[2]);
		glBegin(GL_QUADS);
		glVertex3f(-size, 0, -size);
		glVertex3f(size, 0, -size);
		glVertex3f(size, 0, size);
		glVertex3f(-size, 0, size);
		glEnd();
	}
}

PlaneComponent::PlaneComponent()
{
}


PlaneComponent::~PlaneComponent()
{
}
