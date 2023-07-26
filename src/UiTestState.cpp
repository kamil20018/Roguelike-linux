#include "UiTestState.h"

UiTestState::UiTestState(std::shared_ptr<Context> &context) : context(context), mouseHold(false) {
    slider = sfui::Slider<int>(sf::Vector2f(300.0f, 8.0f), sf::Vector2f(10.0f, 10.0f), 1, 100);
    slider.setBarSize(sf::Vector2f(7.0f, 20.0f));
    slider.setBarColor(sf::Color::White);
    slider.setBarOutline(sf::Color::Black, 1.0f);
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

	if(!mouseHold && mouseHoldChanged && slider.getIsCurrentlyHeld()){
		slider.mouseReleased();
	}

	slider.update(mousePosition);

	// if(slider.wasClicked(mousePosition)){
	// 	std::cout << "clicked\n";
	// } else {
	// 	std::cout << "not clicked\n";
	// }
    //window test
    // window.updateMousePosition(mousePosition);

    // if (mouseHold) {
    //  window.mousePressed(mousePosition));
    // }

    // if (!mouseHold) {
    //  window.mouseReleased();
    // }

	mouseHoldChanged = false;
}

void UiTestState::Draw() {
    _window->clear(sf::Color(200, 0, 0));
    _window->draw(slider);
    _window->display();
}

