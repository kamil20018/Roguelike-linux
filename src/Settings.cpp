#include "Settings.h"

sf::Vector2i Settings::getWindowSize() {
	return WINDOW_SIZE;
}

int Settings::getTileSize() {
	return TILE_SIZE;
}

int Settings::getTileScale() {
	return TILE_SCALE;
}

int Settings::getScaledTileSize() {
	return TILE_SIZE * TILE_SCALE;
}

sf::Vector2i Settings::getChunkSize() {
	return CHUNK_SIZE;
}

void Settings::updateSettings() {
	std::ifstream reader("../src/Settings.json");
    json j;
	reader >> j;
	reader.close();
	WINDOW_SIZE = sf::Vector2i(j["windowSize"][0], j["windowSize"][1]);
	TILE_SIZE = j["tileSize"];
	TILE_SCALE = j["tileScale"];
	CHUNK_SIZE = sf::Vector2i(j["chunkSize"][0], j["chunkSize"][1]);
	std::vector<long long> seeds;
	for (long long seed : j["seed"]) {
		seeds.push_back(seed);
	}
	SEED = seeds;
}

std::vector<long long> Settings::getSeed() {
	return SEED;
}
