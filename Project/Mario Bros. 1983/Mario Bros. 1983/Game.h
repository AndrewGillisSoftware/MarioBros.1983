#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include "AssetManager.h"

class Game
{
public:
	Game(sf::RenderWindow &window);
	~Game();

	void update();
	void draw();

private:
	sf::RenderWindow &window;
	std::vector<Entity *> entities;
	AssetManager assets;
};