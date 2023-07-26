#pragma once
#include <SFML/Graphics.hpp>

namespace sfui {
    class Slider : public sf::Drawable {
        public:
            Slider();
            Slider(sf::Vector2f size, sf::Vector2f position);
        	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        private:
    		sf::Vector2f size;
	    	sf::Vector2f position;
	    	sf::Vector2i oldMousePos;
	    	sf::Vector2i newMousePos;
            sf::Color color;
    };
}