#pragma once
#include "Entity.h"
#include <cstdint>

class Player : public Entity
{
public:
	Player(const Level *level, const AssetManager *assets, sf::Vector2f pos);
	~Player();

	void update();

private:
	uint8_t controls;
};

