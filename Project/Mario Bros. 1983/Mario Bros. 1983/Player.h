#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(Level *level, const AssetManager *assets, sf::Vector2f pos);
	~Player();

	float getGravity() { return 50.0f; }
	float getFriction() { return 50.0f; }
	float getMaxVelocity() { return 50.0f; }
	float getAccelRate() { return 50.0f; }
	float getDecelRate() { return 0.12f; }

	void update(float dt);

private:
	uint8_t controls;

	//Velocity Stuff
	int velocityLimit = 80;
	float accelRate = 2.0f;
	float time = 0;
};

