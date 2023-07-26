#include <SFML/Graphics/CircleShape.hpp>

#include "Game.h"
#include "MainMenu.h"
#include "UiTestState.h"
#include "GamePlay.h"
#include "Settings.h"
Game::Game() : context(std::make_shared<Context>()) {
    sf::Vector2i windowSize = Settings::getWindowSize();
    _window->create(sf::VideoMode(windowSize.x, windowSize.y), "Rougelike", sf::Style::Close);
    _window->setFramerateLimit(60);
    _window->setPosition(sf::Vector2i(200, 200));
    TileLoader::loadTilesToContext(this->context);
    _assets->AddFont("pixel_font", "../Resources/Fonts/manaspc.ttf");
    _assets->AddTexture("goblin", "../Resources/Textures/Enemies/Goblin.png");

    //_states->AddState(std::make_unique<MainMenu>(this->context));
    //_states->AddState(std::make_unique<GamePlay>(this->context, true));
    _states->AddState(std::make_unique<UiTestState>(this->context));


}

Game::~Game() {
}

void Game::Run() {
    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (_window->isOpen()) {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame > TIME_PER_FRAME) {
            timeSinceLastFrame -= TIME_PER_FRAME;
            _states->ProcessStateChange();
            _states->GetCurrent()->ProcessInput();
            _states->GetCurrent()->Update();
            _states->GetCurrent()->Draw();
        }
    }
}