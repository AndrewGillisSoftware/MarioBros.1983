#pragma once
#include "Collidable.h"

static const float gravity = 50.0f;
static const float friction = 50.0f;
static const float maxSpeed = 50.0f;
static const float accellerationRate = 10.0f;
static const float decellerationRate = 10.0f;


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