#include "InputField.h"

sfui::InputField::InputField() : UiElement() {}

sfui::InputField::InputField(sf::Vector2f size, sf::Vector2f position) : UiElement(), size(size), position(position), active(false) {
    backGround.setPosition(position);
    backGround.setSize(size);
}

void sfui::InputField::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(backGround);
}

bool sfui::InputField::wasClicked(sf::Vector2i mousePosition){
    return position.x < mousePosition.x
            && mousePosition.x < position.x + size.x
            && position.y < mousePosition.y
            && mousePosition.y < position.y + size.y;
};

void sfui::InputField::textEntered(std::string text) {
    this->text += text;
    std::cout << this->text << std::endl;
}

void sfui::InputField::mousePressed() {
    active = !active;    
}

bool sfui::InputField::isActive() {
    return active;    
}
