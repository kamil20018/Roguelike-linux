#include "EnemyGenerator.h"

EnemyGenerator::EnemyGenerator(std::shared_ptr<Context> context, std::shared_ptr<World> world) {
	this->world = world;
	this->context = context;
}

EnemyChunk EnemyGenerator::generateChunk(sf::Vector2i chunkPos) {
	EnemyChunk chunk(chunkPos);
	sf::Vector2i offset(chunkPos.x * Settings::getChunkSize().x, chunkPos.y * Settings::getChunkSize().y);
	for (int i = 0; i < 3; i++) {
		sf::Vector2i pos = offset + sf::Vector2i(i + 3, i + 3);
		printf("new enemy pos: %d, %d\n", pos.x, pos.y);
		if (world->isTraversable(pos)) {
			std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(_assets->GetTexture("goblin"), pos, 7, world);
			chunk.addEnemy(enemy);
		}
	}
	return chunk;
}

std::vector<EnemyChunk> EnemyGenerator::loadChunkFromJson(json saveData) {
	std::vector<EnemyChunk> generatedChunks;


	for (json enemyChunk : saveData) {
		json position = enemyChunk["position"];
		EnemyChunk chunk(sf::Vector2i(position[0], position[1]));

		for (auto enemy : enemyChunk["enemies"]) {
			json pos = enemy["position"];
			chunk.addEnemy(std::move(std::make_unique<Enemy>(_assets->GetTexture("goblin"), sf::Vector2i(pos[0], pos[1]), 7, world)));
		}
		generatedChunks.push_back(std::move(chunk));
	}


	return generatedChunks;
}
