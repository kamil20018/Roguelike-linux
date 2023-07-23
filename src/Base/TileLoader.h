#pragma once
#include "Tile.h"
#include "Game.h"
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;

struct Context;

class TileLoader {
public:
	static void loadTilesToContext(std::shared_ptr<Context>& context);
	static sf::Vector2i generateDecorTexturePositions();
};


