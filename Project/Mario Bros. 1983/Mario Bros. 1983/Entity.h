#pragma once
#include "Collidable.h"

class Entity : public Collidable
{
public:
	Entity(const AssetManager *assets, sf::Vector2f pos);
	~Entity();

	inline void flip(bool right);

	//virtual const sf::Texture *GetTexture() = 0;
	virtual bool hasGravity() { return true; }

	sf::FloatRect getBounds();

protected:
	sf::Vector2f velocity;
};

