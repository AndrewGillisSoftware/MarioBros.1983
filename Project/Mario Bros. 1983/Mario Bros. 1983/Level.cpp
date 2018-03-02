#include "Level.h"

Level::Level(Game *game)
{
	this->game = game;
	tiles = new Collidable**[32];
	for (int32_t x = 0; x < 32; x++)
	{
		tiles[x] = new Collidable*[24];
		for (int32_t y = 0; y < 24; y++)
			tiles[x][y] = new Collidable(game->getAssets(), sf::Vector2f(8 * x, 8 * y));
	}
}

Level::~Level()
{
	for (int32_t x = 0; x < 32; x++)
	{
		for (int32_t y = 0; y < 24; y++)
		{
			delete tiles[x][y];
		}
		delete[] tiles[x];
	}
	delete[] tiles;
}

void Level::draw()
{
	for (Entity *entity : entities)
	{
		entity->update();
		game->getWindow()->draw(*entity);
	}
}