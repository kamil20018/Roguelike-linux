#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.h"
#include "Game.h"
#include "GamePlay.h"
#include "UiTestState.h"
class MainMenu : public State {
private:
	std::shared_ptr<Context> context;
	sf::Text gameTitle;
	sf::Text newGameButton;
	sf::Text loadGameButton;
	sf::Text exitButton;

	int currentButton;
	bool buttonPressed;


public:
	MainMenu(std::shared_ptr<Context>& context);
	~MainMenu();

	void Init() override;
	void ProcessInput() override;
	void Update() override;
	void Draw() override;
};