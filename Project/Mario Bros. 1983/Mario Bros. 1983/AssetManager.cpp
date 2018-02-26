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
					assets.insert(std::make_pair(name, texture));
					break;
				}

				case AssetType::Sound:
				{
					sf::SoundBuffer *sound = new sf::SoundBuffer();
					sound->loadFromFile("sound/" + name + ".wav");
					assets.insert(std::make_pair(name, sound));
					break;
				}

				case AssetType::Animation:
				{
					std::ifstream ifs(name + ".json");
					std::string str((std::istreambuf_iterator<char>(ifs)),
						std::istreambuf_iterator<char>());
					json j = json::parse(str);
					for (auto &a : j["animations"].array())
					{
						Animation *animation = new Animation();
						animation->frameCount = a["frames"].get<int32_t>();
						animation->speed = a["speed"].get<int32_t>();
						animation->bounds.left = a["bounds"][0].get<int32_t>();
						animation->bounds.top = a["bounds"][1].get<int32_t>();
						animation->bounds.width = a["bounds"][2].get<int32_t>();
						animation->bounds.height = a["bounds"][3].get<int32_t>();
						animation->loop = a["loop"].get<bool>();
						animation->sounds = new std::string[a["sounds"].array().size()];
						for (size_t i = 0; i < a["sounds"].array().size(); i++)
							animation->sounds[i] = a["sounds"]["name"].get<std::string>();
						assets.insert(std::make_pair(a["name"].get<std::string>(), animation));
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