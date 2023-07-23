#include "WorldGenerator.h"

WorldGenerator::WorldGenerator(std::shared_ptr<Context>& context) : context(context), step(0.005f) {
	//this->globalNoise = std::make_shared<PerlinNoise>();
	this->blur = 0.1f;
	std::random_device rd;
	this->mt = std::mt19937(rd());
	this->blur_dist = std::uniform_real_distribution<float>(-blur, blur);
	this->chunkSize = Settings::getChunkSize();
}



//generates a single chunk
std::pair<sf::Vector2i, TileChunk> WorldGenerator::generateChunk(sf::Vector2i chunkPos) {
	std::vector<std::vector<TileNames>> chunk(chunkSize.y, std::vector<TileNames>(chunkSize.x, TileNames::BASIC_GROUND));
	int leftBound = chunkSize.x * chunkPos.x;
	int bottomBound = chunkSize.y * chunkPos.y;

	for (int x = 0; x < chunkSize.x; x++) {
		for (int y = 0; y < chunkSize.y; y++) {
			//std::cout << x << ", " << y << std::endl;
			float val = noise.perl((leftBound + x) * step, (bottomBound + y) * step);
			chunk[y][x] = getTileName(val);
		}
	}
	return { chunkPos, TileChunk(chunkPos, std::move(chunk) , this->context) };
}

void WorldGenerator::setBlur(float blur) {
	this->blur = blur;
	this->blur_dist = std::uniform_real_distribution<float>(-blur, blur);
}

void WorldGenerator::setStep(float step) {
	this->step = step;
}

TileNames WorldGenerator::getTileName(float noise) {

	noise += this->blur_dist(this->mt);
	if (noise < -0.4f) return TileNames::DEEP_WATER;
	if (noise < -0.25f) return TileNames::SHALLOW_WATER;
	if (noise < -0.16f) return TileNames::BASIC_GROUND;
	if (noise < 0.05f) return TileNames::BASIC_GRASS;
	if (noise < 0.3f) return TileNames::FOREST_GROUND;
	return TileNames::BASIC_WALL;
}
