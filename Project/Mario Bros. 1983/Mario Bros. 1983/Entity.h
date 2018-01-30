#include <SFML/Graphics.hpp>

using namespace sf;

#pragma once
class Entity : public Sprite
{
public:
	Entity();
	~Entity();

private:
	int team;

};

