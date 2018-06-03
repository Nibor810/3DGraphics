#include "GameObject.h"
#include <GL/freeglut.h>


void GameObject::setScale(float x, float y, float z)
{
	scale = new Vector3D(x, y, z);
}

void GameObject::setScaleAll(float scale_)
{
	scale = new Vector3D(scale_, scale_, scale_);
}

void GameObject::setRotation(float x, float y, float z)
{
	rotation = new Vector3D(x, y, z);
}

void GameObject::setRotationAll(float rotation_)
{
	rotation = new Vector3D(rotation_, rotation_, rotation_);
}

void GameObject::setPosition(float x, float y, float z)
{
	position = new Vector3D(x, y, z);
}

void GameObject::drawGameObject()
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	glRotatef(rotation->x, 1, 0, 0);
	glRotatef(rotation->y, 0, 1, 0);
	glRotatef(rotation->z, 0, 0, 1);
	drawComponent->draw();
	glPopMatrix();
}

void GameObject::updateGameObject(float deltaTime)
{
	for (auto c : components)
	{
		c->update();
	}
}

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}