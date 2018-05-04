#pragma once
#include <cstdint>
#include "nlohmann/json.hpp"

using namespace nlohmann;

struct Animation
{
	std::string name;
	int32_t frameCount;
	sf::IntRect bounds;
	int32_t speed;
	bool loop;
	std::string *sounds;
	int32_t *offsets;

	Animation(basic_json<> &element)
	{
		name = element["name"].get<std::string>();
		frameCount = element["frames"].get<int32_t>();
		speed = element["speed"].get<int32_t>();
		bounds.left = element["bounds"][0].get<int32_t>();
		bounds.top = element["bounds"][1].get<int32_t>();
		bounds.width = element["bounds"][2].get<int32_t>();
		bounds.height = element["bounds"][3].get<int32_t>();
		loop = element["loop"].get<bool>();

		sounds = new std::string[frameCount];
		for (size_t i = 0; i < element["sounds"].size(); i++)
		{
			auto &sound = element["sounds"][i];
			for (int32_t frame : sound["frames"])
				sounds[frame] = element["sounds"][i]["name"].get<std::string>();
		}

		offsets = new int32_t[frameCount];
		memset(offsets, 0, sizeof(int32_t) * frameCount);
		for (size_t i = 0; i < element["offsets"].size(); i++)
		{
			offsets[i] = element["offsets"][i].get<int32_t>();
		}
	}

	~Animation()
	{ 
		delete[] sounds;
		delete[] offsets;
	}
};