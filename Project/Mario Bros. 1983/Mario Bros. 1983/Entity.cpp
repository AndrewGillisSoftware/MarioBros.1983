#include "Entity.h"
#include <Windows.h>


Entity::Entity()
{
	animation = nullptr;
}


Entity::~Entity()
{
}

void Entity::Flip(bool right) { setScale(!right ? 0 : -1, 0); }

void Entity::update()
{
	if (animation)
	{
		GetTickCount64
	}
}