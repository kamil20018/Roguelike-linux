#include "UiTestState.h"

UiTestState::UiTestState(std::shared_ptr<Context>& context) : context(context) {
	window = sfui::Window(sf::Vector2f(600, 400));
}

UiTestState::~UiTestState() {

}

void UiTestState::Init() {

}

void UiTestState::ProcessInput() {
	sf::Event event;
	while (_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			_window->close();
		}
		else if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::Escape:
					_states->PopCurrent();
					break;
			}
		}
		else if (event.type == sf::Event::MouseButtonPressed) {
			mouseHold = true;
			mouseReleased = false;
		} 
		else if (event.type == sf::Event::MouseButtonReleased && mouseHold == true) {
			mouseHold = false;
			mouseReleased = true;
			event.type = sf::Event::Count;
		}

	}
}

void UiTestState::Update() {
	//window.handleInput(sf::Mouse::getPosition(*_window), mousePressed);

	window.updateMousePosition(sf::Mouse::getPosition(*_window));

	if (mouseHold) {
		window.mousePressed(sf::Mouse::getPosition(*_window));
	}

	if (mouseReleased) {
		window.mouseReleased();
	}

	//mouseHold = false;
	//mouseReleased = false;
}

void UiTestState::Draw() {
	_window->clear(sf::Color(200, 0, 0));
	_window->draw(window);
	_window->display();
}

