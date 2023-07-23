#pragma once
#include "Tile.h"
#include "Game.h"
#include "PerlinNoise.h"
#include "VectorHash.h"
#include "Settings.h"
#include <unordered_map>

#include "TileChunk.h"
class WorldGenerator {
public:
	WorldGenerator(std::shared_ptr<Context>& context);
	std::pair<sf::Vector2i, TileChunk> generateChunk(sf::Vector2i chunkPos);
	void setBlur(float blur);
	void setStep(float step);
private:
	std::shared_ptr<Context> context;
	TileNames getTileName(float noise);
	sf::Vector2i chunkSize;
	float blur;
	float step;
	std::mt19937 mt;
	std::uniform_real_distribution<float> blur_dist;
	PerlinNoise noise;
};

