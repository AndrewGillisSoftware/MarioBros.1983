#include "Player.h"

Player::Player(const Level *level, const AssetManager *assets, sf::Vector2f pos)
	: Entity(level, assets, pos)
{
	setTexture(*assets->getAsset<sf::Texture>("textures/character_sheet"));
}

void Player::update()
{
	Entity::update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		velocity.y = -80.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		velocity.y = 80.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		PlayAnimation("animations/run");
		velocity.x = -80.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		PlayAnimation("animations/run");
		velocity.x = 80.0f;
	}
	else if (velocity.x != 0)
	{
		PlayAnimation("animations/slide");
	}
	else
		PlayAnimation("animations/idle");
	

	/*if (fabsf(velocity.x) > 0.5f)
		PlayAnimation("animations/run");
	else if (fabsf(velocity.x) < 0.5f && fabsf(velocity.x) > 0.0f)
	{
		PlayAnimation("animations/slide");
	}
	else
		PlayAnimation("animations/idle");*/
}

Player::~Player()
{
}