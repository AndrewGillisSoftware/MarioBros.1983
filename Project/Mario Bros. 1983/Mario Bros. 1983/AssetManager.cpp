#include "AssetManager.h"

static std::vector<std::string> Textures =
{
	"character_sheet_Experimental",
	"misc_sheet",
	"title_sheet" 
};

AssetManager::AssetManager()
{
	Image img;
	for (std::string &name : Textures)
	{
		img.loadFromFile("textures/" + name + ".png");
		img.createMaskFromColor(Color(0x303030));

		Texture texture;
		texture.loadFromImage(img);
		textures.insert(std::make_pair(name, texture));
	}
}

AssetManager::~AssetManager()
{
}

const Texture *AssetManager::getTexture(std::string name) const
{
	auto it = textures.find(name);
	if (it != textures.end())
		return &it->second;
	return nullptr;
}