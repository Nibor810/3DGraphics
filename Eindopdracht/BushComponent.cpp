#include "BushComponent.h"
#include <GL/freeglut.h>

void BushComponent::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	const float size = 1.0f;
	glPushMatrix();
	glBegin(GL_QUADS);
	GLfloat bkColor[3];
	glGetFloatv(GL_COLOR_CLEAR_VALUE, bkColor);
	glClearColor(bkColor[0], bkColor[1], bkColor[2], 0);
	glColor3f(1, 1, 1);


	//bottomplane
	glVertex3f(0, 0, -1);
	glVertex3f(-1, 0, 0);
	glVertex3f(0, 0, 1);
	glVertex3f(1, 0, 0);

	//tussenplanes om de randen
	glTexCoord2d(0, 0); glVertex3f(0, 0, -1);
	glTexCoord2d(0, 1); glVertex3f(0, 2, -1);
	glTexCoord2d(1, 1); glVertex3f(-1, 2, 0);
	glTexCoord2d(1, 0); glVertex3f(-1, 0, 0);

	glTexCoord2d(0, 0); glVertex3f(0, 0, -1);
	glTexCoord2d(0, 1); glVertex3f(0, 2, -1);
	glTexCoord2d(1, 1); glVertex3f(1, 2, 0);
	glTexCoord2d(1, 0); glVertex3f(1, 0, 0);

	glTexCoord2d(0, 0); glVertex3f(0, 0, 1);
	glTexCoord2d(0, 1); glVertex3f(0, 2, 1);
	glTexCoord2d(1, 1); glVertex3f(-1, 2, 0);
	glTexCoord2d(1, 0); glVertex3f(-1, 0, 0);

	glTexCoord2d(0, 0); glVertex3f(0, 0, 1);
	glTexCoord2d(0, 1); glVertex3f(0, 2, 1);
	glTexCoord2d(1, 1); glVertex3f(1, 2, 0);
	glTexCoord2d(1, 0); glVertex3f(1, 0, 0);

	//topplane
	glTexCoord2d(0, 0); glVertex3f(0, 2, -1);
	glTexCoord2d(0, 1); glVertex3f(-1, 2, 0);
	glTexCoord2d(1, 1); glVertex3f(0, 2, 1);
	glTexCoord2d(1, 0); glVertex3f(1, 2, 0);



	//GLfloat bkColor[3];
	glGetFloatv(GL_COLOR_CLEAR_VALUE, bkColor);
	glClearColor(bkColor[0], bkColor[1], bkColor[2], 0);

	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

BushComponent::BushComponent()
{
}


BushComponent::~BushComponent()
{
}
