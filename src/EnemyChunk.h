#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Settings.h"
//#include <memory>
//#include <iostream>
//#include "World.h"
class Enemy;
//class World;

#include "json.hpp"
#include <fstream>
using json = nlohmann::json;

class EnemyChunk : public sf::Drawable {
public:
	EnemyChunk(sf::Vector2i pos);
	void addEnemy(std::shared_ptr<Enemy> enemy);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void takeTurn(WorldData data);
	bool isTraversable(sf::Vector2i pos);
	std::vector<std::shared_ptr<Enemy>> getOutOfBoundsEnemies();
	json serialize();
	sf::Vector2i getPosition();
	std::vector<std::shared_ptr<Enemy>> getEnemies();
	void log();
private:
	sf::Vector2i position;
	sf::Vector2i size;
	bool inBounds(sf::Vector2i pos);
	std::vector<std::shared_ptr<Enemy>> enemies;
	//std::shared_ptr<World> world;
};

