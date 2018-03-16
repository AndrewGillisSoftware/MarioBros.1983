#include "Entity.h"
#include "Level.h"
#include <Windows.h>

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
	velocity *= (1.0f - (deltaSeconds * 1.25f));
	flip(velocity.x > 0);

	const sf::Vector2f &pos = getPosition();
	const Collidable *tile = level->getTile(pos.x / 8, pos.y / 8);
	if (!tile || tile->getType() == ObjectType::None)
		velocity.y = 80.0f;
	else if (velocity.y >= 1.0f)
		velocity.y = 0.0f;
}

void Entity::flip(bool right)
{
	setScale(!right ? 1 : -1, 1);
}