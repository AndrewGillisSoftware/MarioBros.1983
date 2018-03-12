#include "Entity.h"
#include <Windows.h>

Entity::Entity(const AssetManager *assets, sf::Vector2f pos)
	: Collidable(assets, pos)
{

}

Entity::~Entity()
{
}

void Entity::flip(bool right) { setScale(!right ? 0 : -1, 0); }

sf::FloatRect Entity::getBounds()
{
	const Vector2f &pos = getPosition();
	const Vector2u size = getTexture()->getSize();
	if (getTextureRect() != sf::IntRect())
		size = Vector2u(0, 0);

	sf::FloatRect bounds(getPosition().x, getPosition().y, );
}