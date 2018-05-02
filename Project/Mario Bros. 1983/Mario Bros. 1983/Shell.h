#pragma once
#include "Entity.h"

class Shell : public Entity
{
public:
	Shell(Level *level, const AssetManager *assets, sf::Vector2f pos);
	~Shell();

	void update(float dt);

private:
	bool onCollision(Collidable *other);
};

