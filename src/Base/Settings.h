#pragma once
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

using json = nlohmann::json;
class Settings {
public:
	static sf::Vector2i getWindowSize();
	static int getTileSize();
	static int getTileScale();
	static int getScaledTileSize();
	static sf::Vector2i getChunkSize();
	static void updateSettings();
	static std::vector<long long> getSeed();

private:
	static sf::Vector2i WINDOW_SIZE;
	static sf::Vector2i CHUNK_SIZE;
	static int TILE_SIZE;
	static int TILE_SCALE;
	static std::vector<long long> SEED;
};

