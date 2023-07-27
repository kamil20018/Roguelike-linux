#pragma once
#include <SFML/Graphics.hpp>

namespace sfui {
    class Window : public sf::Drawable {
        public:
            Window();
            Window(sf::Vector2f size, sf::Vector2f position);
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            void update(sf::Vector2i mousePosition);
            bool wasClicked(sf::Vector2i mousePosition);

            bool isActive();
            void mousePressed();
            void mouseReleased();
        private:
            sf::Vector2f size;
            sf::Vector2f position;
            sf::Vector2i oldMousePos;
            sf::Vector2i newMousePos;
            sf::Color color;
            void alignToCentre(sf::Vector2i windowSize);
            bool isCurrentlyHeld;
    };
}

