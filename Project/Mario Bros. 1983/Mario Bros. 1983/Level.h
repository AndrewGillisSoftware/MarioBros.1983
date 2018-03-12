#pragma once
#include "Game.h"

class Entity;
class Level
{
public:
	Level(Game *game, std::string file, std::string levelName);
	~Level();

	void draw();

	inline std::string getName() { return name; }

	const std::list<Entity *> &getEntities() const { return entities; }
	Collidable *getTile(uint8_t x, uint8_t y) { return &tiles[x][y]; }

private:
	Game *game;
	std::list<Entity *> entities;
	Collidable tiles[32][24];
	std::string name;
};