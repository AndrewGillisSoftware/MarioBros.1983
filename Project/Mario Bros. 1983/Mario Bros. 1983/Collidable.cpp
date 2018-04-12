#include "Collidable.h"
#include "Level.h"
#include <Windows.h>
#include <iostream>

Collidable::Collidable()
{
	this->assets = nullptr;
	animation = nullptr;
	animStartTime = 0;
	animFrame = 0;
	type = ObjectType::None;
}

Collidable::Collidable(const Level *level, const AssetManager *assets, sf::Vector2f pos)
{
	this->level = level;
	this->assets = assets;
	setPosition(pos);
	animation = nullptr;
	animStartTime = 0;
	animFrame = -1;
	type = ObjectType::Tile;
}

void Collidable::PlayAnimation(std::string name)
{
	name = "animations/" + name;
	if (animation == assets->getAsset<Animation>(name))
		return;
	animStartTime = GetTickCount64();
	animation = assets->getAsset<Animation>(name);
	animFrame = -1;
}
 
void Collidable::update()
{
	//Play animations
	if (animation)
	{
		int32_t frame = ((GetTickCount64() - animStartTime) % (animation->speed * animation->frameCount)) / animation->speed;
		sf::IntRect rect = animation->bounds;
		rect.left += rect.width * frame;
		setTextureRect(rect);

		if (animation->sounds[frame].size() > 0 && frame != animFrame)
		{
			sf::Sound *sound = assets->getAsset<sf::Sound>(animation->sounds[frame]);
			sound->play();
		}
		animFrame = frame;

		if (frame >= animation->frameCount - 1 && !animation->loop)
			animation = nullptr;
	}

	//Set Collisions
	for (Entity *entity : level->getEntities())
	{
		if (entity->getBounds().intersects(getBounds()))
			if (entity->onCollision(this))
				onCollision(this);
	}
}

const sf::FloatRect &Collidable::getBounds() const
{
	const Vector2f &pos = getPosition();
	Vector2u size = getTexture()->getSize();
	const sf::IntRect &rect = getTextureRect();
	if (rect != sf::IntRect(0, 0, 0, 0))
		size = Vector2u(rect.width, rect.height);
	return sf::FloatRect(pos.x, pos.y, size.x, size.y);
}

bool Collidable::onCollision(Collidable *other)
{
	return true;
}