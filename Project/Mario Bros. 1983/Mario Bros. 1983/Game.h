#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include "AssetManager.h"

class Level;
class Game
{
public:
	Game(sf::RenderWindow &window);
	~Game();

	void draw();

	inline AssetManager *getAssets() { return &assets; }
	inline sf::RenderWindow *getWindow() { return &window; }

private:
	sf::RenderWindow &window;
	sf::View view;
	AssetManager assets;
	Level *level;
};