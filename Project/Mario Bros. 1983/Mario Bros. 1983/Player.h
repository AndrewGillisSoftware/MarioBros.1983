#pragma once
#include "Entity.h"
#include <cstdint>

class Player : public Entity
{
public:
	Player(const Level *level, const AssetManager *assets, sf::Vector2f pos);
	~Player();

	void calcVelocity();

	float getGravity() { return 50.0f; }
	float getFriction() { return 50.0f; }
	float getMaxVelocity() { return 50.0f; }
	float getAccelRate() { return 50.0f; }
	float getDecelRate() { return 0.12f; }

	void update();

private:
	uint8_t controls;

	//Velocity Stuff
	int velocityLimit = 80, momentumLimit = 50;
	float accelRate = 2.0f;
	float momentum = 0;
};

