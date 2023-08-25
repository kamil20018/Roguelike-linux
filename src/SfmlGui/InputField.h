#pragma once
#include "UiElement.h"
#include <iostream>
namespace sfui{
    class InputField : public UiElement {
        public:
            InputField();
            InputField(sf::Vector2f size, sf::Vector2f position);
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            bool wasClicked(sf::Vector2i mousePosition);
            void textEntered(std::string text) override;
            void mousePressed() override;
            bool isActive() override;
        private:
            sf::Vector2f size;
            sf::Vector2f position;
            sf::RectangleShape backGround;
            bool active;
            std::string text;
    };
}