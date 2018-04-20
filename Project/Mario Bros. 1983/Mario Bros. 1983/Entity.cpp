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
	float y = pos.y;
	const Collidable *tile = level->getTile(pos.x / 8, (pos.y + getGlobalBounds().height) / 8);
	if(!tile || tile->getType() == ObjectType::None)
	{
		velocity.y = std::min(150.0f, velocity.y + 800 * deltaSeconds);
		onGround = false;
	}
	else if (getGlobalBounds().intersects(tile->getGlobalBounds()))
	{
		velocity.y = 0.0f;
		setPosition(pos.x, tile->getPosition().y - getGlobalBounds().height);
		onGround = true;
	}
	
	// the code above checks the tile BELOW the player, making this check impossible up there
	// So, we must check for the tile at the player separately
	tile = level->getTile(pos.x / 8, pos.y / 8);
	if (tile && tile->getType() != ObjectType::None && getGlobalBounds().intersects(tile->getGlobalBounds()) && y > tile->getPosition().y)
	{
		// Go to the bottom of the tile
		setPosition(pos.x, tile->getPosition().y + tile->getGlobalBounds().height);
	}

	update(deltaSeconds);
}

void Entity::flip(bool right)
{
	setOrigin(getBounds().width / 2, 0);
	setScale(!right ? 1 : -1, 1);
}