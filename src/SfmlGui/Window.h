#pragma once
#include "UiElement.h"

namespace sfui {
    class Window : public UiElement {
        public:
            Window();
            Window(sf::Vector2f size, sf::Vector2f position);
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            void mouseMovement(sf::Vector2i mousePosition) override;

            bool wasClicked(sf::Vector2i mousePosition);

        private:
            sf::Vector2f size;
            sf::Vector2f position;
            sf::Vector2i oldMousePos;
            sf::Vector2i newMousePos;
            sf::Color color;
            void alignToCentre(sf::Vector2i windowSize);
    };
}

