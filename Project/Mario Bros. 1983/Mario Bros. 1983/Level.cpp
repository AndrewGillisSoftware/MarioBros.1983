#include "Level.h"
#include "Entity.h"

Level::Level(Game *game, std::string file, std::string levelName)
{
	this->game = game;
	for (int32_t x = 0; x < 32; x++)
	{
		for (int32_t y = 0; y < 24; y++)
			tiles[x][y] = Collidable();
	}

	std::ifstream ifs(file);
	std::string str((std::istreambuf_iterator<char>(ifs)),
		std::istreambuf_iterator<char>());
	json j = json::parse(str);

	std::unordered_map<std::string, sf::IntRect> textures;
	for (auto &level : j["levels"])
	{
		name = level["name"].get<std::string>();
		if (name != levelName)
			continue;

		for (auto &texture : level["textures"])
		{
			std::string texName = texture["name"].get<std::string>();
			sf::IntRect texBounds(
				texture["bounds"][0].get<int32_t>(),
				texture["bounds"][1].get<int32_t>(),
				texture["bounds"][2].get<int32_t>(),
				texture["bounds"][3].get<int32_t>());
			textures.insert(std::make_pair(texName, texBounds));
		}

		for (auto &object : level["objects"])
		{
			ObjectType type = object["type"].get<ObjectType>();
			std::string texture = object["texture"].get<std::string>();
			sf::Vector2i pos(object["position"][0], object["position"][1]);

			uint8_t length = object["length"].get<uint8_t>();
			for (uint8_t x = 0; x < length; x++, pos.x++)
			{
				Collidable tile(this, game->getAssets(), sf::Vector2f(8 * pos.x, 8 * pos.y));
				tile.setTexture(*game->getAssets()->getAsset<sf::Texture>("textures/misc_sheet_experimental"));
				tile.setTextureRect(textures[texture]);
				tiles[pos.x][pos.y] = tile;
			}
		}
		break;
	}

	Player *player = new Player(this, game->getAssets(), sf::Vector2f(15, 250));
	entities.push_back(player);
}

Level::~Level()
{
	for (Entity *entity : entities)
		delete entity;
}

void Level::draw()
{
	for (Entity *entity : entities)
	{
		entity->update();
		game->getWindow()->draw(*entity);
	}

	for (int32_t x = 0; x < 32; x++)
	{
		for (int32_t y = 0; y < 24; y++)
		{
			game->getWindow()->draw(tiles[x][y]);
		}
	}
}

const Collidable *Level::getTile(uint8_t x, uint8_t y) const
{
	if (x >= 32 || y >= 24)
		return nullptr;
	return &tiles[x][y];
}