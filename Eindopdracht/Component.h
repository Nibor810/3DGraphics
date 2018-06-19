#pragma once
class GameObject;
class Component
{
public:
	GameObject * component_game_object;
	virtual void update(float elapsedTime) = 0;
	Component();
	~Component();
};

