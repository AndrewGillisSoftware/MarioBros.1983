#include "Collidable.h"
#include "Level.h"
#include <Windows.h>

Collidable::Collidable()
{
	this->assets = nullptr;
	animation = nullptr;
	animStartTime = 0;
	animFrame = 0;
}

Collidable::Collidable(const Level *level, const AssetManager *assets, sf::Vector2f pos)
{
	this->level = level;
	this->assets = assets;
	setPosition(pos);
	animation = nullptr;
	animStartTime = 0;
	animFrame = -1;
}

void Collidable::PlayAnimation(std::string name)
{
	animStartTime = GetTickCount64();
	animation = assets->getAsset<Animation>(name);
}

void Collidable::update()
{
	if (animation)
	{
		int32_t frame = ((GetTickCount64() - animStartTime) % (animation->speed * animation->frameCount)) / animation->speed;
		sf::IntRect rect = animation->bounds;
		rect.left += rect.width * frame;
		setTextureRect(rect);

		if (animation->sounds[frame].size() > 0 && (frame == 0 || frame != animFrame))
		{
			sf::Sound *sound = assets->getAsset<sf::Sound>(animation->sounds[frame]);
			sound->play();
		}
		animFrame = frame;

		if (frame >= animation->frameCount - 1 && !animation->loop)
			animation = nullptr;
	}

	for (Entity *entity : level->getEntities())
	{

	}
}

bool Collidable::onCollision(Collidable *other)
{
	return true;
}