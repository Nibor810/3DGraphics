#include "TreeComponent.h"
#include <GL/freeglut.h>


void TreeComponent::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textureID);
	const float size = 1.0f;
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);

	//korte stam
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
	glVertex3f(0, 2, -1);
	glVertex3f(-1, 2, 0);
	glVertex3f(0, 2, 1);
	glVertex3f(1, 2, 0);

	// lange stam
	//bottomplane
	glVertex3f(0, 2, -0.5f);
	glVertex3f(-0.5f, 2, 0);
	glVertex3f(0, 2, 0.5f);
	glVertex3f(0.5f, 2, 0);

	//tussenplanes om de randen
	glTexCoord2d(0, 0); glVertex3f(0, 2, -0.5f);
	glTexCoord2d(0, 1); glVertex3f(-0.5f, 2, 0);
	glTexCoord2d(1, 1); glVertex3f(-0.5f, 7, 0);
	glTexCoord2d(1, 0); glVertex3f(0, 7, -0.5f);

	glTexCoord2d(0, 0); glVertex3f(0, 2, -0.5f);
	glTexCoord2d(0, 1); glVertex3f(0.5f, 2, 0);
	glTexCoord2d(1, 1); glVertex3f(0.5f, 7, 0);
	glTexCoord2d(1, 0); glVertex3f(0, 7, -0.5f);

	glTexCoord2d(0, 0); glVertex3f(0, 2, 0.5f);
	glTexCoord2d(0, 1); glVertex3f(-0.5f, 2, 0);
	glTexCoord2d(1, 1); glVertex3f(-0.5f, 7, 0);
	glTexCoord2d(1, 0); glVertex3f(0, 7, 0.5f);

	glTexCoord2d(0, 0); glVertex3f(0, 2, 0.5f);
	glTexCoord2d(0, 1); glVertex3f(0.5f, 2, 0);
	glTexCoord2d(1, 1); glVertex3f(0.5f, 7, 0);
	glTexCoord2d(1, 0); glVertex3f(0, 7, 0.5f);

	//Vanaf hier alles groen
	glColor3f(0, 1, 0);
	//topplane
	glVertex3f(0, 7, -0.5f);
	glVertex3f(-0.5f, 7, 0);
	glVertex3f(0, 7, 0.5f);
	glVertex3f(0.5f, 7, 0);

	//bladeren
	//bottompane
	glTexCoord2d(0, 0); glVertex3f(0, 7, -3);
	glTexCoord2d(0, 1); glVertex3f(-3, 7, 0);
	glTexCoord2d(1, 1); glVertex3f(0, 7, 3);
	glTexCoord2d(1, 0); glVertex3f(3, 7, 0);

	//tussenplanes om de randen
	glTexCoord2d(0, 0); glVertex3f(0, 7, -3);
	glTexCoord2d(0, 1); glVertex3f(-3, 7, 0);
	glTexCoord2d(1, 0); glVertex3f(-3, 13, 0);
	glTexCoord2d(1, 1); glVertex3f(0, 13, -3);

	glTexCoord2d(0, 0); glVertex3f(0, 7, 3);
	glTexCoord2d(0, 1); glVertex3f(-3, 7, 0);
	glTexCoord2d(1, 0); glVertex3f(-3, 13, 0);
	glTexCoord2d(1, 1); glVertex3f(0, 13, 3);

	glTexCoord2d(0, 0); glVertex3f(0, 7, -3);
	glTexCoord2d(0, 1); glVertex3f(3, 7, 0);
	glTexCoord2d(1, 0); glVertex3f(3, 13, 0);
	glTexCoord2d(1, 1); glVertex3f(0, 13, -3);

	glTexCoord2d(0, 0); glVertex3f(0, 7, 3);
	glTexCoord2d(0, 1); glVertex3f(3, 7, 0);
	glTexCoord2d(1, 0); glVertex3f(3, 13, 0);
	glTexCoord2d(1, 1); glVertex3f(0, 13, 3);



	//topplane
	glTexCoord2d(0, 0); glVertex3f(0, 13, -3);
	glTexCoord2d(0, 1); glVertex3f(-3, 13, 0);
	glTexCoord2d(1, 1); glVertex3f(0, 13, 3);
	glTexCoord2d(1, 0); glVertex3f(3, 13, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

TreeComponent::TreeComponent()
{
}


TreeComponent::~TreeComponent()
{
}
