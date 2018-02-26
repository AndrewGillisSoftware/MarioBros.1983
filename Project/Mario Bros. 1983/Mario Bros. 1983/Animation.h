#pragma once
#include <cstdint>

struct Animation
{
	int32_t frameCount;
	sf::IntRect bounds;
	int32_t speed;
	bool loop;
	std::string *sounds;

	~Animation() { delete[] sounds; }
};