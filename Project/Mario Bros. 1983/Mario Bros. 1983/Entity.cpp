#include "Entity.h"
#include <Windows.h>

Entity::Entity(const AssetManager *assets, sf::Vector2f pos)
{
	this->assets = assets;
	setPosition(pos);
	animation = nullptr;
}

Entity::~Entity()
{
}

void Entity::PlayAnimation(std::string name)
{
	startAnimTime = GetTickCount64();
	animation = assets->getAsset<Animation>(name);
}

void Entity::Flip(bool right) { setScale(!right ? 0 : -1, 0); }

void Entity::update()
{
	if (animation)
	{
		int frame = ((GetTickCount64() - startAnimTime) % (animation->speed * animation->frameCount)) / animation->speed;
		sf::IntRect rect = animation->bounds;
		rect.left += rect.width * frame;
		setTextureRect(rect);

		if (frame >= animation->frameCount - 1 && !animation->loop)
			animation = nullptr;
	}
}