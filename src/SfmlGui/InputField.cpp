#include "InputField.h"

sfui::InputField::InputField() : UiElement() {}

sfui::InputField::InputField(sf::Vector2f size, sf::Vector2f position, std::shared_ptr<std::string> text) : UiElement(), size(size), position(position), active(false), text(text) {
    backGround.setPosition(position);
    backGround.setSize(size);
    font.loadFromFile("../Resources/Fonts/manaspc.ttf");
    std::cout << "really?\n";
}

void sfui::InputField::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(backGround);
    sf::Text written(*text, font);
    written.setPosition(this->position);
    written.setColor(sf::Color::Black);
    written.setCharacterSize(this->size.y);
    target.draw(written);
}

bool sfui::InputField::wasClicked(sf::Vector2i mousePosition){
    return position.x < mousePosition.x
            && mousePosition.x < position.x + size.x
            && position.y < mousePosition.y
            && mousePosition.y < position.y + size.y;
};

void sfui::InputField::textEntered(char text) {
    if(std::isalnum(text) || text == ' '){
        *this->text += text;
    } else if ((int)text == 8 && this->text->size() > 0){
        this->text->pop_back();
    }
}

void sfui::InputField::mousePressed() {
    active = !active;    
}

bool sfui::InputField::isActive() {
    return active;    
}
