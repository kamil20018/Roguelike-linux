#include "UiTestState.h"

UiTestState::UiTestState(std::shared_ptr<Context> &context) : context(context), mouseHold(false) {
    slider = sfui::Slider<int>(sf::Vector2f(300.0f, 8.0f), sf::Vector2f(10.0f, 10.0f), 1, 100);
    slider.setBarSize(sf::Vector2f(7.0f, 20.0f));
    slider.setBarColor(sf::Color::White);
    slider.setBarOutline(sf::Color::Black, 1.0f);

	window = sfui::Window(sf::Vector2f(200.0f, 100.0f), sf::Vector2f(100.0f, 100.0f));
}

UiTestState::~UiTestState() {}

void UiTestState::Init() {}

void UiTestState::ProcessInput() {
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window->close();
        } else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    _states->PopCurrent();
                    break;
            }
        } else if (event.type == sf::Event::MouseButtonPressed) {
			if(!mouseHold){
				mouseHoldChanged = true;
			}
            mouseHold = true;
        } else if (event.type == sf::Event::MouseButtonReleased && mouseHold == true) {
			if(mouseHold){
				mouseHoldChanged = true;
			}
            mouseHold = false;
            event.type = sf::Event::Count;
        }

    }
}

void UiTestState::Update() {
	
	mousePosition = sf::Mouse::getPosition(*_window);

	if(mouseHold && mouseHoldChanged){
		if(slider.wasClicked(mousePosition)){
			slider.mousePressed();
		}
	}

	if(!mouseHold && mouseHoldChanged && slider.isActive()){
		slider.mouseReleased();
	}

	slider.update(mousePosition);

	// uncomment to check if the slider returns a correct value
	// std::cout << slider.getValue() << std::endl;

	if(mouseHold && mouseHoldChanged){
		if(window.wasClicked(mousePosition)){
			window.mousePressed();
		}
	}

	if(!mouseHold && mouseHoldChanged && window.isActive()){
		window.mouseReleased();
	}

	window.update(mousePosition);


	mouseHoldChanged = false;
}

void UiTestState::Draw() {
    _window->clear(sf::Color(200, 0, 0));
    _window->draw(window);
    _window->draw(slider);
    _window->display();
}

