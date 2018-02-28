#include "Entity.h"
#include <Windows.h>

Entity::Entity(const AssetManager *assets, sf::Vector2f pos)
{
	this->assets = assets;
	setPosition(pos);
	animation = nullptr;
	animStartTime = 0;
	animFrame = -1;
}

Entity::~Entity()
{
}

void Entity::PlayAnimation(std::string name)
{
	animStartTime = GetTickCount64();
	animation = assets->getAsset<Animation>(name);
}

void Entity::Flip(bool right) { setScale(!right ? 0 : -1, 0); }

void Entity::update()
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
}