#include "Game.h"

Game::Game(sf::RenderWindow &window)
	: window(window)
{
	entities.push_back(new Player(assets.getTexture("character_sheet_Experimental"), sf::Vector2f(15, 15)));
}

Game::~Game()
{
	for (Entity *entity : entities)
		delete entity;
}

void Game::update()
{
	for (Entity *entity : entities)
	{
		entity->update();
	}
}

void Game::draw()
{
	for (Entity *entity : entities)
	{
		window.draw(*entity);
	}
}