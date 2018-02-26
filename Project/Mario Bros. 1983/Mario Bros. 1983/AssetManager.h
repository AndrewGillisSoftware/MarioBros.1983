#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include <unordered_map>
#include "nlohmann/json.hpp"
#include <fstream>

using namespace sf;
using namespace nlohmann;

enum class AssetType
{
	Texture,
	Sound,
	Animation
};

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	template <typename AssetT>
	const AssetT *getAsset(std::string name) const
	{
		auto it = assets.find(name);
		if (it != assets.end())
			return static_cast<AssetT *>(it->second);
		return nullptr;
	}

private:
	std::unordered_map<std::string, void *> assets;
};

