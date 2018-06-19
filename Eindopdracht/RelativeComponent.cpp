#include "RelativeComponent.h"
#include "GameObject.h"
#include <math.h>
#define PI 3.14159265358979323846f


void RelativeComponent::update(float elapsedTime)
{
	//component_game_object
	//center of this object need to be position of other object
	//centerObject->position;//position before any rotations or translates
	//centerObject->rotation;//in degrees for each axis
	//centerObject->offset;//from position, after the rotation
	//dus position = position
	//dan die position -> offset op de juiste rotatie
	//dan heb je juiste positie
	//Vector3D temp = centerObject->position + centerObject->offset;
	//temp.rotate(x,y,z) -> uitkomst = punt.


	float xRotation = centerObject->rotation->x * (PI / 180.0f);
	float yRotation = centerObject->rotation->y * (PI / 180.0f);
	float zRotation = centerObject->rotation->z * (PI / 180.0f);

	float vMatrix[3][1] = { { centerObject->position->x+centerObject->offset->x },{ centerObject->position->y + centerObject->offset->y },{ centerObject->position->z + centerObject->offset->z } };//vector matrix
	float rMatrix[3][3] = { 
		{ (cos(yRotation)*cos(zRotation)), (-cos(yRotation)*sin(zRotation)), (sin(yRotation)) },
		{ (sin(xRotation)*sin(yRotation)*cos(zRotation) + cos(xRotation)*sin(zRotation)), (-sin(xRotation)*sin(yRotation)*sin(zRotation) + cos(xRotation)*cos(zRotation)), (-sin(xRotation)*cos(yRotation)) } ,
		{ (-cos(xRotation)*sin(yRotation)*cos(zRotation) + sin(xRotation)*sin(zRotation)),(cos(xRotation)*sin(yRotation)*sin(zRotation) + sin(xRotation)*cos(zRotation)),(cos(xRotation)*cos(yRotation))}
	};//rotation matrix for all axis
	float product[3][1] = { { 0 },{ 0 },{ 0 } }; //result
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			product[i][0] += (rMatrix[i][j] * vMatrix[j][0]);
		}
	}
	component_game_object->setPosition(*product[0], *product[1], *product[2]);
}

RelativeComponent::RelativeComponent()
{
}


RelativeComponent::~RelativeComponent()
{
}
