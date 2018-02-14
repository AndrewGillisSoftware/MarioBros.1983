#include "Entity.h"
#include <Windows.h>

Entity::Entity(const sf::Texture *texture, sf::Vector2f pos)
{
	setTexture(*texture);
	setPosition(pos);
	animation = nullptr;
}

Entity::~Entity()
{
}

void Entity::PlayAnimation(int index)
{
	startAnimTime = GetTickCount64();
	animation = GetAnimation(index);
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