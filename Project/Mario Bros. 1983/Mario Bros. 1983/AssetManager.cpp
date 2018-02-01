#include "AssetManager.h"

static std::vector<std::string> Textures =
{
	"character_sheet",
	"misc_sheet",
	"title_sheet"
};

AssetManager::AssetManager()
{
	Texture texture;


	for (std::string &name : Textures)
	{
		texture.loadFromFile(name.append(".png"));
		textures.insert(std::make_pair(name, texture));
	}
}

AssetManager::~AssetManager()
{
}

const Texture *AssetManager::getTexture(std::string name)
{
	auto it = textures.find(name);
	if (it != textures.end())
		return &it->second;
	return nullptr;
}