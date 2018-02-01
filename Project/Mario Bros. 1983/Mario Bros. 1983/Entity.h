#pragma once
#include <SFML/Graphics.hpp>

struct Animation
{
	int frameCount;
	sf::IntRect bounds;
	int speed;
	bool loop;
};

class Entity : public sf::Sprite
{
public:
	Entity();
	~Entity();

	void PlayAnimation(int index);
	inline void Flip(bool right);

	virtual void update();

	virtual Animation *GetAnimiation(int index) = 0;
	virtual bool HasGravity() { return true; }

private:
	int team;
	Animation *animation;

};

