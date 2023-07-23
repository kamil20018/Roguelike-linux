#pragma once
#include "Enemy.h"
#include "EnemyChunk.h"
#include "Game.h"
#include "Settings.h"
#include "World.h"
class EnemyGenerator {
public:
	EnemyGenerator(std::shared_ptr<Context> context, std::shared_ptr<World> world);
	EnemyChunk generateChunk(sf::Vector2i chunkPos);
	std::vector<EnemyChunk> loadChunkFromJson(json saveData);
private:
	std::shared_ptr<Context> context;
	std::shared_ptr<World> world;
};

