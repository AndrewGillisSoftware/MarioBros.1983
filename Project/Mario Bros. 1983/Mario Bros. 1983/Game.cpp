#include "Game.h"
#include "Level.h"

Game::Game(sf::RenderWindow &window)
	: window(window)
{
	view.reset(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
	view.setViewport(sf::FloatRect(0, 0, 2.0f, 2.0f));
	window.setView(view);
	level = new Level(this, "levels.json", "test");
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