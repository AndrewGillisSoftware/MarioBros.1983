
#include "Player.h"

Player::Player()
{
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
			static Animation animation;
			animation.frameCount = 5;
			animation.bounds = sf::IntRect{1,12,18,21};
			animation.speed = 5;
			return &animation;
		}
	}
}