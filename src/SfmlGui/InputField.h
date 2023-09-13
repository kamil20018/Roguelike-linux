#pragma once
#include "UiElement.h"
#include <iostream>
#include <cctype>
#include <memory>
namespace sfui{
    class InputField : public UiElement {
        public:
            InputField();
            InputField(sf::Vector2f size, sf::Vector2f position, std::shared_ptr<std::string> text);
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            bool wasClicked(sf::Vector2i mousePosition);
            void textEntered(char text) override;
            void mousePressed() override;
            bool isActive() override;
        private:
            sf::Vector2f size;
            sf::Vector2f position;
            sf::RectangleShape backGround;
            bool active;
            std::shared_ptr<std::string> text;
            sf::Font font;
    };
}