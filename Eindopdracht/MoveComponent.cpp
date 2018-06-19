#include "MoveComponent.h"
#include "GameObject.h"


void MoveComponent::setRotationSpeed(float x, float y, float z)
{
	xRotationSpeed = x;
	yRotationSpeed = y;
	zRotationSpeed = z;
}

void MoveComponent::update(float elapsedTime)
{
	component_game_object->setRotation(component_game_object->rotation->x - (xRotationSpeed * elapsedTime), component_game_object->rotation->y - (yRotationSpeed * elapsedTime), component_game_object->rotation->z - (zRotationSpeed * elapsedTime));
}

MoveComponent::MoveComponent()
{
}


MoveComponent::~MoveComponent()
{
}
