#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "AssetManager.h"

class Entity : public sf::Sprite
{
public:
	Entity(const AssetManager *assets, sf::Vector2f pos);
	~Entity();

	void PlayAnimation(std::string name);
	inline void Flip(bool right);

	virtual void update();

	//virtual const sf::Texture *GetTexture() = 0;
	virtual bool HasGravity() { return true; }

protected:
	sf::Vector2f position, velocity;

private:
	const AssetManager *assets;
	int team;
	const Animation *animation;
	uint64_t animStartTime;
	int32_t animFrame;
	sf::Sound sound;
};

