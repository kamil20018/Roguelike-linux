#pragma once

#include "State.h"
#include "Game.h"
#include "Hero.h"
#include <memory>
#include "MapParser.h"
#include "Settings.h"
#include "Tile.h"
#include "WorldGenerator.h"
#include "TileChunk.h"
#include "World.h"
#include "TextField.h"
#include "ActorManager.h"

#include "Enemy.h"
#include "EnemyChunk.h"

#include "json.hpp"
#include <fstream>
using json = nlohmann::json;

class GamePlay : public State {
public:
	GamePlay(std::shared_ptr<Context> context, bool load);
	void Init() override;
	void ProcessInput() override;
	void Update() override;
	void Draw() override;
private:

	void newGameInit();
	void loadGameInit();
	void positionMouseOutline();
	void zoomView();
	bool moveHero();
	void onClickMovement();
	void enemyTurn();

	std::shared_ptr<Context> context;
	std::shared_ptr<World> world; //done
	std::unique_ptr<ActorManager> actorManager;
	std::unique_ptr<Hero> hero; //done
	std::vector<std::shared_ptr<Enemy>> activeEnemies;

	sf::Vector2i moveDir;
	std::vector<sf::Vector2i> heroPath;

	sf::View gameplayView;
	float zoomFactor;


	sf::View UiView;
	int mouseScrollDelta;
	int tileSize;
	int totalChunks;
	sf::Vector2i mouseTilePos;
	bool mouseButtonDown;
	sf::RectangleShape mouseOutline;
	bool keyPressed;
	bool passTurn;

	TextField notification;

	sf::Vector2f vecIntToFloat(sf::Vector2i vec);
	std::vector<sf::Vector2i> getPath(sf::Vector2i begin, sf::Vector2i end, bool unitVector, bool withStart = false, bool withEnd = false);
	void saveGame();
	json serialize();

};

struct Node {
	Node(sf::Vector2i position, int g_val, int h_val) {
		this->position = position;
		this->g_val = g_val;
		this->h_val = h_val;
		this->f_val = g_val + h_val;
	}
	sf::Vector2i position;
	int g_val; //start node to our node
	int h_val; // potential min path to destination
	int f_val; // sum of g and h
	sf::Vector2i parentPos;
	bool operator <(Node const& rhs) const {
		if (rhs.f_val == this->f_val) {
			return this->h_val < rhs.h_val;
		}
		return this->f_val < rhs.f_val;
	}

};
