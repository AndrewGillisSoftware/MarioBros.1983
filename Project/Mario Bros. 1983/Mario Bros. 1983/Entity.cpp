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
	const Collidable *tile = checkTileCollision(pos.x / 8, (pos.y + getGlobalBounds().height) / 8);
	if(!tile)
	{
		velocity.y = std::min(150.0f, velocity.y + 800 * deltaSeconds);
		onGround = false;
	}
	else
	{
		velocity.y = 0.0f;
		setPosition(pos.x, tile->getPosition().y - getGlobalBounds().height);
		onGround = true;
	}
	
	// the code above checks the tile BELOW the player, making this check impossible up there
	// So, we must check for the tile at the player separately
	tile = checkTileCollision(pos.x / 8, pos.y / 8);
	if (tile && pos.y > tile->getPosition().y)
	{
		// Go to the bottom of the tile
		setPosition(pos.x, tile->getPosition().y + tile->getGlobalBounds().height);
	}

	for (int i = -1; i < ceilf(getGlobalBounds().height / 8.0f) + 1; i++)
	{
		tile = checkTileCollision((pos.x / 8) - (getGlobalBounds().width / 8) /*WHERE WE LEFT OFF*/, (pos.y / 8) + i);
		if (tile)
		{
			velocity.x = 0;
			setPosition(tile->getPosition().x + tile->getGlobalBounds().width + (getGlobalBounds().width / 2), pos.y);
			break;
		}

		tile = checkTileCollision((pos.x / 8) + 1, (pos.y / 8) + i);
		if (tile)
		{
			velocity.x = 0;
			setPosition(tile->getPosition().x - getGlobalBounds().width / 2, pos.y);
		}

		/*for (int j = -1; j < ceilf(getGlobalBounds().width / 8.0f) + 1; j++)
		{

		}*/
	}

	tile = checkTileCollision((pos.x / 8) - 1, pos.y / 8);
	if (tile && pos.x < tile->getPosition().x + tile->getGlobalBounds().width / 2)
	{
		setPosition(tile->getPosition().x + tile->getGlobalBounds().width, pos.y);
	}

	update(deltaSeconds);
}

const Collidable *Entity::checkTileCollision(uint8_t x, uint8_t y)
{
	const Collidable *tile = level->getTile(x, y);
	return tile && tile->getType() != ObjectType::None && getGlobalBounds().intersects(tile->getGlobalBounds()) ? tile : nullptr;
}

void Entity::flip(bool right)
{
	setOrigin(getBounds().width / 2, 0);
	setScale(!right ? 1 : -1, 1);
}