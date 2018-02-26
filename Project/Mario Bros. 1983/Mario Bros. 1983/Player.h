#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(const AssetManager *assets, sf::Vector2f pos);
	~Player();

	void changeVelocity();
};

