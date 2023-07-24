#pragma once

#include "UiTestState.h"
#include "Game.h"
#include "State.h"
#include <memory>
#include "MapParser.h"
#include <iterator>
#include "Hero.h"
//#include "PerlinNoise.h"
#include "TextField.h"
#include "TextField2.h"
#include "Window.h"
struct Context;

class UiTestState : public State {
public:
	UiTestState(std::shared_ptr<Context>& context);
	~UiTestState();
	void Init() override;
	void ProcessInput() override;
	void Update() override;
	void Draw() override;
private:
	std::shared_ptr<Context> context;
	sfui::Window window;
	bool mouseHold;
	bool mouseReleased;
	
	//TextField field;
	//std::unordered_map<sf::Vector2i, Tile> tileMap;
	//std::unique_ptr<Hero> hero;
	//PerlinNoise noise;
	//std::array<std::array<float, 598>, 598> pairs;
	//int w;
	//int h;
	//int counter;
};