#pragma once
#include "Game.h"
#include "Entity.h"
#include "Player.h"

class Level
{
public:
	Level(Game *game);
	~Level();

	void draw();

private:
	Game *game;
	std::vector<Entity *> entities;
	Collidable*** tiles;
};