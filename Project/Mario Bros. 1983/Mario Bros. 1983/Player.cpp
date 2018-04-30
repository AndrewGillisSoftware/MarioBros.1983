#include "Player.h"
#include <iostream>

Player::Player(const Level *level, const AssetManager *assets, sf::Vector2f pos)
	: Entity(level, assets, pos)
{
	setTexture(*assets->getAsset<sf::Texture>("textures/character_sheet"));
}

void Player::update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && onGround)
	{
		velocity.y = -300;
		PlayAnimation("jump");
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		velocity.x = std::max(-70.0f, velocity.x - 400 * dt);
		if (onGround)
			PlayAnimation("run");
		lastDir = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		velocity.x = std::min(70.0f, velocity.x + 400 * dt);
		if (onGround)
			PlayAnimation("run");
		lastDir = true;
	}
	else if (velocity.x > 30.0f || velocity.x < -30.0f)
	{
		velocity.x *= 1 - dt * 4;
		PlayAnimation("slide");
	}
	else
	{
		velocity.x = 0;
		PlayAnimation("idle");
	}
}

Player::~Player()
{
}