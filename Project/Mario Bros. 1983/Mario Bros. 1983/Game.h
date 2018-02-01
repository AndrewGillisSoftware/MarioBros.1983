#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Game
{
public:
	Game(const sf::RenderWindow &window);
	~Game();

	void update();
	void draw();

private:
	const sf::RenderWindow &window;
	std::vector<Entity *> entities;
};