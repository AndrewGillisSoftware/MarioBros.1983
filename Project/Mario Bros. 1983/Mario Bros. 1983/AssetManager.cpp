#include "AssetManager.h"

static const std::unordered_map<AssetType, std::vector<std::string>> ToLoad =
{
	{
		AssetType::Texture,
		{
			"character_sheet",
			"misc_sheet",
			"title_sheet"
		}
	},
	{
		AssetType::Sound,
		{
			"boss",
			"jump",
			"run",
			"select"
		}
	}
};

AssetManager::AssetManager()
{
	for (auto it = ToLoad.begin(); it != ToLoad.end(); ++it)
	{
		for (const std::string &name : it->second)
		{
			void *asset = nullptr;
			switch (it->first)
			{
				case AssetType::Texture:
				{
					sf::Image img;
					img.loadFromFile("textures/" + name + ".png");
					img.createMaskFromColor(sf::Color(0x303030));

					sf::Texture *texture = new sf::Texture();
					texture->loadFromImage(img);
					break;
				}

				case AssetType::Sound:
				{
					sf::SoundBuffer *sound = new sf::SoundBuffer();
					sound->loadFromFile("sounds/" + name + ".wav");
					asset = sound;
					break;
				}
			}

			if (asset)
				assets.insert(std::make_pair(name, asset));
		}
	}
}

AssetManager::~AssetManager()
{
	for (auto it = assets.begin(); it != assets.end(); ++it)
		delete it->second;
}