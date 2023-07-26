#include "Slider.h"

sfui::Slider::Slider() {}

sfui::Slider::Slider(sf::Vector2f size, sf::Vector2f position) {
    slider.setFillColor(sf::Color::White);
    slider.setSize(size);
    slider.setPosition(position);
}

void sfui::Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(slider);
    target.draw(bar);
}


void sfui::Slider::setBarSize(sf::Vector2f size) {
    sf::Vector2f sliderSize = slider.getSize();
    sf::Vector2f sliderPosition = slider.getPosition();
    bar.setSize(size);
    bar.setPosition(sf::Vector2f(
        sliderPosition.x - size.x / 2.0f,
        sliderPosition.y - size.y / 2.0f + sliderSize.y / 2.0f
    ));
}

void sfui::Slider::setBarColor(sf::Color color) {
    bar.setFillColor(color);
}

void sfui::Slider::setBarOutline(sf::Color color, float thickness) {
    bar.setOutlineColor(color);
    bar.setOutlineThickness(thickness);
}
