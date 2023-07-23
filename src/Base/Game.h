#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetManager.h"
#include "StateManager.h"
#include "TileLoader.h"
#include "VectorHash.h"


#define _window this->context->window
#define _states this->context->states
#define _assets this->context->assets

class StateManager;

struct Context {
	std::unique_ptr<AssetManager> assets;
	std::unique_ptr<StateManager> states;
	std::unique_ptr<sf::RenderWindow> window;

	Context() {
		assets = std::make_unique<AssetManager>();
		states = std::make_unique<StateManager>();
		window = std::make_unique<sf::RenderWindow>();
	}
};

class Game {
private:
	std::shared_ptr<Context> context;
	const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

public:
	Game();
	~Game();
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
	void Run();
};

namespace utils {
	const std::vector<sf::Vector2i> unitVectors{
		sf::Vector2i(-1, 0),
		sf::Vector2i(1, 0),
		sf::Vector2i(-1, 1),
		sf::Vector2i(0, 1),
		sf::Vector2i(0, -1),
		sf::Vector2i(1, -1),
		sf::Vector2i(1, 1),
		sf::Vector2i(-1, -1)

	};
}