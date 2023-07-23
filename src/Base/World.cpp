#include "World.h"


World::World(std::shared_ptr<Context> context) : context(context), worldGenerator(WorldGenerator(context)) {
	removeUnloaded = true;
	worldGenerator.setBlur(0.01f);
	worldGenerator.setStep(0.005f);
	updateLoadedChunks();
}

World::World(std::shared_ptr<Context> context, json saveData) : context(context), worldGenerator(WorldGenerator(context)) {

	json centerChunk = saveData["centerChunk"];
	this->centreChunk = sf::Vector2i(centerChunk[0], centerChunk[1]);

	removeUnloaded = true;
	worldGenerator.setBlur(0.01f);
	worldGenerator.setStep(0.005f);
	updateLoadedChunks();
}


//bool World::isTraversable(sf::Vector2i globalPos) {
//	sf::Vector2i chunkPos = globalPosToChunk(globalPos);
//	if (loadedChunks.find(chunkPos) == loadedChunks.end()) return false;
//
//	return chunks.at(chunkPos).isTraversable(globalPos);
//}

sf::Vector2f World::vecIntToFloat(sf::Vector2i vec) {
	return sf::Vector2f((float)vec.x, (float)vec.y);
}

void World::updateLoadedChunks() {

	sf::Vector2i chunkSize = Settings::getChunkSize();

	this->loadedChunks.clear();
	std::vector<sf::Vector2i> positions = utils::unitVectors;
	positions.push_back(sf::Vector2i());


	for (sf::Vector2i pos : utils::unitVectors) {
		sf::Vector2i chunkPos = pos + centreChunk;
		if (!chunks.contains(chunkPos)) {
			totalTiles += chunkSize.x * chunkSize.y;
			totalChunks++;
			chunks.insert(worldGenerator.generateChunk(chunkPos));
		}
		loadedChunks.insert(chunkPos);

	}
	loadedChunks.insert(centreChunk);
	if (!chunks.contains(centreChunk)) {
		totalTiles += chunkSize.x * chunkSize.y;
		totalChunks++;
		chunks.insert(worldGenerator.generateChunk(centreChunk));
	}

	if (this->removeUnloaded) {
		std::vector<sf::Vector2i> chunksToRemove;
		for (auto const& pair : chunks) {
			bool found = false;
			for (sf::Vector2i pos : positions) {
				if (pair.first == pos + this->centreChunk) found = true;
			}
			if (not found) {
				chunksToRemove.push_back(pair.first);
			}
		}
		for (sf::Vector2i toRem : chunksToRemove) {
			std::cout << toRem.x << ", " << toRem.y << std::endl;
			chunks.erase(toRem);
		}
	}

	std::cout << "total chunks: " << totalChunks << " total tiles: " << totalTiles << std::endl;
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (sf::Vector2i chunkPos : loadedChunks) {
		target.draw(chunks.at(chunkPos), states);
	}
}

json World::serialize() {
	json world;
	world["centerChunk"] = { centreChunk.x, centreChunk.y };
	return world;
}

