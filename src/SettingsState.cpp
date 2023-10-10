#include "SettingsState.h"

SettingsState::SettingsState(std::shared_ptr<Context> &context) 
        :context(context)
        , textWindowX(std::make_shared<std::string>())
        , textWindowY(std::make_shared<std::string>()) 
{
    sf::Text text;
    text.setFont(context->assets->GetFont("pixel_font"));
    text.setString("windowX");
    text.setPosition(sf::Vector2f(10, 0));
    optionTexts.push_back(text);
    text.setString("windowY");
    text.setPosition(sf::Vector2f(10, 50));
    optionTexts.push_back(text);

    UiElements.push_back(std::make_unique<sfui::InputField>(sf::Vector2f(100.0f, 20.0f), sf::Vector2f(200.0f, 10.0f), textWindowX));
    UiElements.push_back(std::make_unique<sfui::InputField>(sf::Vector2f(100.0f, 20.0f), sf::Vector2f(200.0f, 60.0f), textWindowY));
}

SettingsState::~SettingsState() {}

void SettingsState::Init() {}

void SettingsState::ProcessInput() {
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

void SettingsState::Update() {
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

void SettingsState::Draw() {
    _window->clear(sf::Color(200, 0, 0));
    std::cout << "chuj1" << std::endl;
    for(auto &UiElement : UiElements) {
        _window->draw(*UiElement);
    }
    std::cout << "chuj1" << std::endl;
    for(auto text: optionTexts){
        _window->draw(text);
    }
    std::cout << "chuj1" << std::endl;
    _window->display();
}

