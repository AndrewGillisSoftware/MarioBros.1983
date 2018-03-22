#include "Entity.h"
#include "Level.h"
#include <Windows.h>
#include <iostream>

Entity::Entity(const Level *level, const AssetManager *assets, sf::Vector2f pos)
	: Collidable(level, assets, pos)
{
}

void Entity::update()
{
	Collidable::update();
	sf::Time deltaTime = clock.restart();
	float deltaSeconds = deltaTime.asSeconds();
	move(velocity * deltaSeconds);
	velocity *= (1.0f - (deltaSeconds * 13.37f));
	flip(velocity.x > 0);

	const sf::Vector2f &pos = getPosition();
	const Collidable *tile = level->getTile(pos.x / 8, (pos.y + getGlobalBounds().height) / 8);
	if (!tile || tile->getType() == ObjectType::None)
		velocity.y = 50.0f;
	else if (getGlobalBounds().intersects(tile->getGlobalBounds()))
	{
		std::cout << "INTERSECTION";
		velocity.y = 0.0f;
		setPosition(pos.x, tile->getPosition().y - getGlobalBounds().height);
	}

}

void Entity::flip(bool right)
{
	setOrigin(getBounds().width / 2, 0);
	setScale(!right ? 1 : -1, 1);
}