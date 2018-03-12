#include "Game.h"
#include "Level.h"

Game::Game(sf::RenderWindow &window)
	: window(window)
{
	level = new Level(this, "levels.json", "Level 1");
}

Game::~Game()
{
	delete level;
}

void Game::draw()
{
	if (level)
		level->draw();
}