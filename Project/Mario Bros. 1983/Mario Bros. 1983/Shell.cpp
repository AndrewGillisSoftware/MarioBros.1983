#include "Shell.h"


Shell::Shell(Level *level, const AssetManager *assets, sf::Vector2f pos)
	: Entity(level, assets, pos)
{

}

void Shell::update(float dt)
{

}

bool Shell::onCollision(Collidable *other)
{

	return true;
}

Shell::~Shell()
{
}