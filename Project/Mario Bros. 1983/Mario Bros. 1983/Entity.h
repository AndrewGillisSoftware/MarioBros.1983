#pragma once
#include "Collidable.h"

class Entity : public Collidable
{
public:
	Entity(const Level *level, const AssetManager *assets, sf::Vector2f pos);
	virtual ~Entity() { }

	virtual void update();

	void flip(bool right);

	virtual bool hasGravity() { return true; }

protected:
	sf::Vector2f velocity;

private:
	sf::Clock clock;
};