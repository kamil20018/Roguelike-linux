#include "Slider.h"

sfui::Slider::Slider() {}

sfui::Slider::Slider(sf::Vector2f size, sf::Vector2f position) : size(size), position(position) {}

void sfui::Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::RectangleShape rectangle;
    rectangle.setFillColor(color);
    rectangle.setSize(size);
    rectangle.setPosition(position);
    target.draw(rectangle);
}

