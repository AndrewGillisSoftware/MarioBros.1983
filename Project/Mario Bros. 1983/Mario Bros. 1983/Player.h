#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	enum {
		run, idle, slide, death, death_fire, jump
	};

	Player(const sf::Texture *texture, sf::Vector2f pos);
	~Player();

	const Animation *GetAnimation(int index);
	void changeVelocity();
};

