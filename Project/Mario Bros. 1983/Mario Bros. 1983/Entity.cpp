#include "Entity.h"
#include <Windows.h>

Entity::Entity(const AssetManager *assets, sf::Vector2f pos)
{
}

Entity::~Entity()
{
}

void Entity::Flip(bool right) { setScale(!right ? 0 : -1, 0); }
