#include "Player.h"

Player::Player(const AssetManager *assets, sf::Vector2f pos)
	: Entity(assets, pos)
{
	setTexture(*assets->getAsset<sf::Texture>("textures/character_sheet"));
	PlayAnimation("animations/shell");
}

Player::~Player()
{
}

void Player::changeVelocity()
{
	sf::Vector2f nv;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		nv.x = velocity.x;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

	}



	velocity.x;
}
