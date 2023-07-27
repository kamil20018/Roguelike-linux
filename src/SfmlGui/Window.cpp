#include "Window.h"

namespace sfui {
    Window::Window() : size(sf::Vector2f(1.0f, 1.0f)), UiElement() {

    }

    Window::Window(sf::Vector2f size, sf::Vector2f position) : size(size), position(position), UiElement() {

    }

    void Window::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        sf::RectangleShape rectangle;
        rectangle.setFillColor(sf::Color::Black);
        rectangle.setSize(size);
        rectangle.setPosition(position);
        target.draw(rectangle);
    }

    void Window::update(sf::Vector2i mousePosition) {
        oldMousePos = newMousePos;
        newMousePos = mousePosition;

        if (isCurrentlyHeld) {
            position += sf::Vector2f(newMousePos.x - oldMousePos.x, newMousePos.y - oldMousePos.y);
        }

    }

    bool Window::wasClicked(sf::Vector2i mousePosition) {
        return position.x < mousePosition.x
               && mousePosition.x < position.x + size.x
               && position.y < mousePosition.y
               && mousePosition.y < position.y + size.y;
    }



    void Window::alignToCentre(sf::Vector2i windowSize) {
        //sf::Vector2i windowSize = Settings::getWindowSize();
        float xPos = ((float)windowSize.x - this->size.x) / 2.0f;
        float yPos = ((float)windowSize.y - this->size.y) / 2.0f;
        this->position = sf::Vector2f(xPos, yPos);
    }

}


