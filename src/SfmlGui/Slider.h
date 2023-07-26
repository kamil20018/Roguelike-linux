#pragma once
#include <SFML/Graphics.hpp>

namespace sfui {
    class Slider : public sf::Drawable {
        public:
            Slider();
            Slider(sf::Vector2f size, sf::Vector2f position);

            void setBarSize(sf::Vector2f size);
            void setBarColor(sf::Color color);
            void setBarOutline(sf::Color color, float thickness);
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        private:
            //slider params
            sf::Color color;
            sf::RectangleShape slider;

            //movable bar params
            float barPostion;
            sf::RectangleShape bar;
           
            //mouse info
            sf::Vector2i oldMousePos;
            sf::Vector2i newMousePos;
    };
}