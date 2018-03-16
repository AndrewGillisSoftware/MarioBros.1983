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
		velocity.y = 80.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocity.x = -80.0f;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocity.x = 80.0f;

	if (fabsf(velocity.x) > 0.5f)
		PlayAnimation("animations/run");
	else
		PlayAnimation("animations/idle");
}

Player::~Player()
{
}