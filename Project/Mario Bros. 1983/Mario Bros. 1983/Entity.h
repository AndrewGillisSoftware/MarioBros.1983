#pragma once
#include "Collidable.h"

class Entity : public Collidable
{
public:
	Entity(const AssetManager *assets, sf::Vector2f pos);
	~Entity();

	inline void Flip(bool right);

	//virtual const sf::Texture *GetTexture() = 0;
	virtual bool HasGravity() { return true; }

protected:
	sf::Vector2f position, velocity;

private:
	
};

