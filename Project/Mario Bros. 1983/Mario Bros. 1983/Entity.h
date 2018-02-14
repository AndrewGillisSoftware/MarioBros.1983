#pragma once
#include <SFML/Graphics.hpp>

struct Animation
{
	int frameCount;
	sf::IntRect bounds;
	int speed;
	bool loop;

	Animation(int frameCount, sf::IntRect bounds, int speed, bool loop) :
		frameCount(frameCount), bounds(bounds), speed(speed), loop(loop) {}
};

class Entity : public sf::Sprite
{
public:
	Entity(const sf::Texture *texture, sf::Vector2f pos);
	~Entity();

	void PlayAnimation(int index);
	inline void Flip(bool right);

	virtual void update();

	virtual const Animation *GetAnimation(int index) = 0;
	virtual bool HasGravity() { return true; }

private:
	int team;
	const Animation *animation;
	unsigned long long startAnimTime;
};

