#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"

namespace sfui {
	class Window : public sf::Drawable {
	public:
		Window();
		Window(sf::Vector2f size);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void updateMousePosition(sf::Vector2i mousePosition);
		bool wasClicked(sf::Vector2i mousePosition);
		void mousePressed(sf::Vector2i mousePosition);
		void mouseReleased();
	private:
		sf::Vector2f size;
		sf::Vector2f position;
		sf::Vector2i oldMousePos;
		sf::Vector2i newMousePos;
		sf::Color color;
		void alignToCentre();
		bool mouseHold;
		bool movingWindow;
	};
}

