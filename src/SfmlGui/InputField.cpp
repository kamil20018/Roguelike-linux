#include "InputField.h"

sfui::InputField::InputField() : UiElement() {}

sfui::InputField::InputField(sf::Vector2f size, sf::Vector2f position) : UiElement(), size(size), position(position) {
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
