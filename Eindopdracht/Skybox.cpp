#include "Skybox.h"

Skybox::Skybox() {}
Skybox::~Skybox() {}

void Skybox::load(float zfar, int text_id)
{
	const float dist = zfar * cos(45.0f);
	const float th = 1.0f / 3.0f;
	const float of = (1.0f / 1024.0f) / 2;

	texture_Skybox = text_id;
	id_Skybox = glGenLists(1);
	glNewList(id_Skybox, GL_COMPILE);

	// Top
	glBegin(GL_QUADS);

	glTexCoord2f(0.25f + of, 1 * th - of); glVertex3f(dist, dist, dist);
	glTexCoord2f(0.50f - of, 1 * th - of); glVertex3f(-dist, dist, dist);
	glTexCoord2f(0.50f - of, 0.0f + of); glVertex3f(-dist, dist, -dist);
	glTexCoord2f(0.25f + of, 0.0f + of); glVertex3f(dist, dist, -dist);

	// Bottom

	glTexCoord2f(0.25f + of, 1.0f - of); glVertex3f(dist, -dist, -dist);
	glTexCoord2f(0.50f - of, 1.0f - of); glVertex3f(-dist, -dist, -dist);
	glTexCoord2f(0.50f - of, 2 * th + of); glVertex3f(-dist, -dist, dist);
	glTexCoord2f(0.25f + of, 2 * th + of); glVertex3f(dist, -dist, dist);


	// Front

	glTexCoord2f(0.25f, 2 * th - of); glVertex3f(dist, -dist, dist);
	glTexCoord2f(0.50f, 2 * th - of); glVertex3f(-dist, -dist, dist);
	glTexCoord2f(0.50f, 1 * th + of); glVertex3f(-dist, dist, dist);
	glTexCoord2f(0.25f, 1 * th + of); glVertex3f(dist, dist, dist);

	// Back

	glTexCoord2f(0.75f, 2 * th - of); glVertex3f(-dist, -dist, -dist);
	glTexCoord2f(1.00f, 2 * th - of); glVertex3f(dist, -dist, -dist);
	glTexCoord2f(1.00f, 1 * th + of); glVertex3f(dist, dist, -dist);
	glTexCoord2f(0.75f, 1 * th + of); glVertex3f(-dist, dist, -dist);


	// Right

	glTexCoord2f(0.50f, 2 * th - of); glVertex3f(-dist, -dist, dist);
	glTexCoord2f(0.75f, 2 * th - of); glVertex3f(-dist, -dist, -dist);
	glTexCoord2f(0.75f, 1 * th + of); glVertex3f(-dist, dist, -dist);
	glTexCoord2f(0.50f, 1 * th + of); glVertex3f(-dist, dist, dist);

	// Left

	glTexCoord2f(0.00f, 2 * th - of); glVertex3f(dist, -dist, -dist);
	glTexCoord2f(0.25f, 2 * th - of); glVertex3f(dist, -dist, dist);
	glTexCoord2f(0.25f, 1 * th + of); glVertex3f(dist, dist, dist);
	glTexCoord2f(0.00f, 1 * th + of); glVertex3f(dist, dist, -dist);


	glEnd();

	glEndList();
}


void Skybox::draw(float x, float y, float z) const
{
	glPushMatrix();
	glColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_Skybox);
	glTranslatef(x, y, z);
	glCallList(id_Skybox);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glPopMatrix();

}
