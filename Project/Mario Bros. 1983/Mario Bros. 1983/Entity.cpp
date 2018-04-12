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
	flip(lastDir);
	
	Vector2f oldPosition = getPosition();
	sf::Time deltaTime = clock.restart();
	float deltaSeconds = deltaTime.asSeconds();
	move(velocity * deltaSeconds);

	const sf::Vector2f &pos = getPosition();
	const Collidable *tile = level->getTile(pos.x / 8, (pos.y + getGlobalBounds().height) / 8);
	if (/*velocity.y >= -0.001 &&*/ (!tile || tile->getType() == ObjectType::None))
	{
		velocity.y = std::min(150.0f, velocity.y + 800 * deltaSeconds);
		onGround = false;
	}
	else if (getGlobalBounds().intersects(tile->getGlobalBounds()))
	{
		std::cout << "INTERSECTION";
		velocity.y = 0.0f;
		if (pos.y + getGlobalBounds().height >= tile->getPosition().y)
		{
			setPosition(pos.x, tile->getPosition().y + getGlobalBounds().height);
		}
		else
			setPosition(pos.x, tile->getPosition().y - getGlobalBounds().height);
		onGround = true;
	}

	update(deltaSeconds);
}

void Entity::flip(bool right)
{
	setOrigin(getBounds().width / 2, 0);
	setScale(!right ? 1 : -1, 1);
}