#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
using namespace sf;

#pragma once
class AssetManager
{
public:
	AssetManager();
	~AssetManager();
	const Texture *getTexture(std::string);

private:
	std::unordered_map<std::string, sf::Texture> textures;
};

