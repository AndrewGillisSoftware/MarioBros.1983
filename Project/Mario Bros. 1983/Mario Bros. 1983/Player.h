#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	enum {
		run, idle, slide, death, death_fire
	};

	Player();
	~Player();

	const Animation *GetAnimation(int index);
};

