#include "UiTestState.h"
#include <typeinfo>
UiTestState::UiTestState(std::shared_ptr<Context> &context) : context(context), textInField(std::make_shared<std::string>()) {

    sliderValue = std::make_shared<int>(10);
    std::unique_ptr<sfui::Slider<int>> slider = std::make_unique<sfui::Slider<int>>(sf::Vector2f(300.0f, 8.0f), sf::Vector2f(10.0f, 10.0f), 1, 100, sliderValue);
    slider->setBarSize(sf::Vector2f(7.0f, 20.0f))
    .setBarColor(sf::Color::White)
    .setBarOutline(sf::Color::Black, 1.0f);

    UiElements.push_back(std::move(slider));
    UiElements.push_back(std::make_unique<sfui::Window>(sf::Vector2f(200.0f, 100.0f), sf::Vector2f(100.0f, 100.0f)));
    UiElements.push_back(std::make_unique<sfui::InputField>(sf::Vector2f(200.0f, 20.0f), sf::Vector2f(300.0f, 300.0f), textInField));

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

            sfui::ClickState::mouseButtonPressed();

        } else if (event.type == sf::Event::MouseButtonReleased) {

            event.type = sf::Event::Count;
            sfui::ClickState::mouseButtonReleased();
        } else if (event.type == sf::Event::TextEntered){
            currText = (char)event.text.unicode;
        }

    }
}

void UiTestState::Update() {

    mousePosition = sf::Mouse::getPosition(*_window);

    for(auto &UiElement : UiElements) {
        if(sfui::ClickState::justPressed()) {
            if(UiElement->wasClicked(mousePosition)) {
                UiElement->mousePressed();
            }
        }

        if(sfui::ClickState::justReleased() && UiElement->isActive()) {
            UiElement->mouseReleased();
        }

        if(currText && UiElement->isActive()){
            UiElement->textEntered(*currText);
        }

        UiElement->mouseMovement(mousePosition);
    }

    currText = std::nullopt;
    sfui::ClickState::update();
}

void UiTestState::Draw() {
    _window->clear(sf::Color(200, 0, 0));

    for(auto &UiElement : UiElements) {
        _window->draw(*UiElement);
    }

    _window->display();
}

