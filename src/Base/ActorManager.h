#pragma once
#include "Chunked.h"
#include "EnemyGenerator.h"
#include "EnemyChunk.h"

#include "json.hpp"
#include <fstream>
using json = nlohmann::json;

class ActorManager : public Chunked<EnemyChunk>, public sf::Drawable {
public:
	ActorManager(std::shared_ptr<Context> context, std::shared_ptr<World> world);
	ActorManager(std::shared_ptr<Context> context, std::shared_ptr<World> world, json saveData);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void updateEnemyChunks();
	std::vector<std::shared_ptr<Enemy>> getEnemies();
	json serialize();
	void log();
private:
	std::shared_ptr<Context> context;
	EnemyGenerator enemyGenerator;
	void updateLoadedChunks() override;
	void updateEnemiesChunkPos();
	
};

