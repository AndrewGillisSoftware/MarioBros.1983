#include "Player.h"

Player::Player(const sf::Texture *texture, sf::Vector2f pos)
	: Entity(texture, pos)
{
	PlayAnimation(run);
}

Player::~Player()
{
}

const Animation *Player::GetAnimation(int index)
{
	switch (index)
	{
		case run:
		{
			static Animation animation(6, sf::IntRect{ 1,12,18,21 }, 200, true);
			return &animation;
		}
	}
}