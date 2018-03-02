#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "AssetManager.h"
#include <SFML/Graphics/Sprite.hpp>

class Collidable : public sf::Sprite
{
public:
	Collidable(const AssetManager *assets, sf::Vector2f pos);
	~Collidable();

	void PlayAnimation(std::string name);

	virtual void update();

protected:
	const AssetManager *assets;

private:
	const Animation *animation;
	uint64_t animStartTime;
	int32_t animFrame;
	sf::Sound sound;
};