#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "json.hpp"

using json = nlohmann::json;

class Hero : public sf::Drawable {
public:
	Hero(const sf::Texture& texture);
	Hero(const sf::Texture& texture, json saveData);
	void move(sf::Vector2i dir);
	void setTexture(const sf::Texture& texture);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2i getPosition();
	json serialize();
private:
	sf::Vector2i position;
	sf::Texture texture;
};

