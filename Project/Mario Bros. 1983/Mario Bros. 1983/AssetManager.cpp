#include "AssetManager.h"

static const std::unordered_map<AssetType, std::vector<std::string>> ToLoad =
{
	{
		AssetType::Texture,
		{
			"character_sheet",
			"misc_sheet",
			"misc_sheet_experimental",
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
	},
	{
		AssetType::Animation,
		{
			"animations"
		}
	}
};

AssetManager::AssetManager()
{
	for (auto it = ToLoad.begin(); it != ToLoad.end(); ++it)
	{
		for (const std::string &name : it->second)
		{
			switch (it->first)
			{
				case AssetType::Texture:
				{
					sf::Image img;
					img.loadFromFile("textures/" + name + ".png");
					img.createMaskFromColor(sf::Color(0x303030));

					sf::Texture *texture = new sf::Texture();
					texture->loadFromImage(img);
					assets.insert(std::make_pair("textures/" + name, texture));
					break;
				}

				case AssetType::Sound:
				{
					sf::SoundBuffer *buffer = new sf::SoundBuffer();
					buffer->loadFromFile("sounds/" + name + ".wav");
					sf::Sound *sound = new sf::Sound(*buffer);
					assets.insert(std::make_pair("sounds/" + name, sound));
					break;
				}

				case AssetType::Animation:
				{
					std::ifstream ifs(name + ".json");
					std::string str((std::istreambuf_iterator<char>(ifs)),
						std::istreambuf_iterator<char>());
					json j = json::parse(str);
					for (auto &a : j["animations"])
					{
						Animation *animation = new Animation(a);
						assets.insert(std::make_pair("animations/" + animation->name, animation));
					}
					break;
				}
			}
		}
	}
}

AssetManager::~AssetManager()
{
	for (auto it = assets.begin(); it != assets.end(); ++it)
		delete it->second;
}