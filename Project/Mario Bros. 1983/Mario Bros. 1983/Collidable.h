#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "AssetManager.h"
#include <SFML/Graphics/Sprite.hpp>
#include <string>

enum class ObjectType
{
	None,
	Tile,
	Pow,
	Pipe
};

class Level;
class Collidable : public sf::Sprite
{
public:
	Collidable();
	Collidable(Level *level, const AssetManager *assets, sf::Vector2f pos);
	virtual ~Collidable() { }

	void PlayAnimation(std::string name);

	virtual void update();

	virtual bool onCollision(Collidable *other);

	const sf::FloatRect &getBounds() const;
	ObjectType getType() const { return type; }

protected:
	const AssetManager *assets;
	Level *level;

private:
	const Animation *animation;
	uint64_t animStartTime;
	int32_t animFrame;
	ObjectType type;
};