#include "Player.h"

Player::Player(const Level *level, const AssetManager *assets, sf::Vector2f pos)
	: Entity(level, assets, pos)
{
	setTexture(*assets->getAsset<sf::Texture>("textures/character_sheet"));
}

void Player::calcVelocity()
{
}

void Player::update()
{
	Entity::update();

	calcVelocity();

	


	if (velocity.x != 0.0f)
	{
		PlayAnimation("animations/slide");
	}
	else
		PlayAnimation("animations/idle");

}


void Player::calcVelocity()
{
	



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (momentum < momentumLimit)
		{
			momentum += 1;
		}
		PlayAnimation("animations/run");
		lastDir = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		PlayAnimation("animations/run");
		lastDir = true;
	}

	sf::Time deltaTime = clock.restart();
	float deltaSeconds = deltaTime.asSeconds();
	move(velocity * deltaSeconds);
}

Player::~Player()
{
}