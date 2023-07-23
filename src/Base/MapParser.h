#pragma once
#include "Tile.h"
#include "Game.h"
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;

class MapParser {
public:
	static std::unordered_map<sf::Vector2i, Tile> parseMap(std::shared_ptr<Context>& context, std::string fileName);
};

