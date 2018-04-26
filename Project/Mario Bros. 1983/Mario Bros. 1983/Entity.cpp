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
	int yIter;
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
	// So, we must check for the tile at (above) the player separately
	tile = checkTileCollision(((pos.x - getGlobalBounds().width / 2) / 8), pos.y / 8);
	if (tile && pos.y > tile->getPosition().y)
	{
		// Go to the bottom of the tile
		setPosition(pos.x, tile->getPosition().y + tile->getGlobalBounds().height);
	}

	////Vertical Collision
	//for (int i = 0; i < ceilf(getGlobalBounds().width / 8.0f) + 1; i++)
	//{
	//	//Below Player
	//	tile = checkTileCollision(((pos.x - (getGlobalBounds().width / 2)) / 8) + i, (pos.y + getGlobalBounds().height) / 8);
	//	if (!tile)
	//	{
	//		velocity.y = std::min(150.0f, velocity.y + 800 * deltaSeconds);
	//		onGround = false;
	//	}
	//	else
	//	{
	//		velocity.y = 0.0f;
	//		setPosition(pos.x, tile->getPosition().y - getGlobalBounds().height);
	//		onGround = true;
	//	}

	//	// the code above checks the tile BELOW the player, making this check impossible up there
	//	// So, we must check for the tile at (above) the player separately
	//	tile = checkTileCollision(((pos.x - getGlobalBounds().width / 2) / 8) + i, pos.y / 8);
	//	if (tile && pos.y > tile->getPosition().y)
	//	{
	//		// Go to the bottom of the tile
	//		setPosition(pos.x, tile->getPosition().y + tile->getGlobalBounds().height);
	//	}
	//}


	//Horizontal Collision
	for (int i = 0; i < ceilf(getGlobalBounds().height / 8.0f) + 1; i++)
	{
		//if last iteration, test at max height rather than adding another tile's worth of height
		if (i == ceilf(getGlobalBounds().height / 8.0f))
			yIter = getGlobalBounds().height;
		else
			yIter = i;

		//Check left tiles
		tile = checkTileCollision(((pos.x - getGlobalBounds().width / 2) /*- 1*/) / 8, (pos.y / 8) + yIter);
		if (tile)
		{
			velocity.x = 0;
			setPosition(tile->getPosition().x + tile->getGlobalBounds().width + (getGlobalBounds().width / 2), pos.y);
			break;
		}

		//Check right tiles
		tile = checkTileCollision(((pos.x + getGlobalBounds().width / 2) /*+ 1*/) / 8, (pos.y / 8) + yIter);
		if (tile)
		{
			velocity.x = 0;
			setPosition(tile->getPosition().x - getGlobalBounds().width / 2, pos.y);
		}
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