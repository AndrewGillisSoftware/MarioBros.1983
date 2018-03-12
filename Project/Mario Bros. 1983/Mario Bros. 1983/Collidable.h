#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "AssetManager.h"
#include <SFML/Graphics/Sprite.hpp>

enum class ObjectType
{
	Tile,
	Pow,
	Pipe
};

class Level;
class Collidable : public sf::Sprite
{
public:
	Collidable();
	Collidable(const Level *level, const AssetManager *assets, sf::Vector2f pos);
	virtual ~Collidable() { }

	void PlayAnimation(std::string name);

	virtual void update();

	virtual bool onCollision(Collidable *other);

protected:
	const AssetManager *assets;

private:
	const Level *level;
	const Animation *animation;
	uint64_t animStartTime;
	int32_t animFrame;
	ObjectType type;
};