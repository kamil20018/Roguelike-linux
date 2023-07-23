#include "MainMenu.h"

#include <SFML/Window/Event.hpp>

MainMenu::MainMenu(std::shared_ptr<Context>& context)
	: context(context) {

	buttonPressed = false;
	currentButton = 0;
}

MainMenu::~MainMenu() {
}

void MainMenu::Init() {


	// Title
	gameTitle.setFont(context->assets->GetFont("pixel_font"));
	gameTitle.setString("RougeLike");
	gameTitle.setOrigin(gameTitle.getLocalBounds().width / 2, gameTitle.getLocalBounds().height / 2);
	gameTitle.setPosition((float)context->window->getSize().x / 2,
						  (float)context->window->getSize().y / 2 - 150.f);

	// new game Button
	newGameButton.setFont(context->assets->GetFont("pixel_font"));
	newGameButton.setString("New Game");
	newGameButton.setOrigin(newGameButton.getLocalBounds().width / 2,
							newGameButton.getLocalBounds().height / 2);
	newGameButton.setPosition((float)context->window->getSize().x / 2,
							  (float)context->window->getSize().y / 2 - 25.f);
	newGameButton.setCharacterSize(20);


	// load game Button
	loadGameButton.setFont(context->assets->GetFont("pixel_font"));
	loadGameButton.setString("Load Game");
	loadGameButton.setOrigin(loadGameButton.getLocalBounds().width / 2,
							 loadGameButton.getLocalBounds().height / 2);
	loadGameButton.setPosition((float)context->window->getSize().x / 2,
							   (float)context->window->getSize().y / 2);
	loadGameButton.setCharacterSize(20);



	// Exit Button
	exitButton.setFont(context->assets->GetFont("pixel_font"));
	exitButton.setString("Exit");
	exitButton.setOrigin(exitButton.getLocalBounds().width / 2,
						 exitButton.getLocalBounds().height / 2);
	exitButton.setPosition((float)context->window->getSize().x / 2,
						   (float)context->window->getSize().y / 2 + 25.f);
	exitButton.setCharacterSize(20);
}

void MainMenu::ProcessInput() {
	sf::Event event;
	while (context->window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			context->window->close();
		}
		else if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::Up: {
					currentButton--;
					break;
				}
				case sf::Keyboard::Down: {
					currentButton++;
					break;
				}
				case sf::Keyboard::Return: {
					buttonPressed = true;

					break;
				}
				default: {
					break;
				}
			}
			if (currentButton < 0) {
				currentButton = 2;
			}
			currentButton %= 3;
		}
	}
}

void MainMenu::Update() {

	switch (currentButton) {
		case 0:
			newGameButton.setFillColor(sf::Color::White);
			loadGameButton.setFillColor(sf::Color::Black);
			exitButton.setFillColor(sf::Color::Black);
			break;
		case 1:
			newGameButton.setFillColor(sf::Color::Black);
			loadGameButton.setFillColor(sf::Color::White);
			exitButton.setFillColor(sf::Color::Black);
			break;
		case 2:
			newGameButton.setFillColor(sf::Color::Black);
			loadGameButton.setFillColor(sf::Color::Black);
			exitButton.setFillColor(sf::Color::White);
			break;
	}

	if (buttonPressed) {
		switch (currentButton) {
			case 0:
				context->states->AddState(std::make_unique<GamePlay>(context, false), true);
				//context->states->AddState(std::make_unique<UiTestState>(context));
				
				break;
			case 1:
				context->states->AddState(std::make_unique<GamePlay>(context, true), true);
				break;
			case 2:
				context->window->close();
				break;
		}
	}
}

void MainMenu::Draw() {
	context->window->clear(sf::Color::Blue);
	context->window->draw(gameTitle);
	context->window->draw(newGameButton);
	context->window->draw(loadGameButton);
	context->window->draw(exitButton);
	context->window->display();
}
