#include "Hero.h"

Hero::Hero(const sf::Texture& texture) : position(sf::Vector2i(0, 0)) {
	this->texture = texture;
}

Hero::Hero(const sf::Texture& texture, json saveData) {



	this->texture = texture;
	auto pos = saveData["position"];
	this->position = sf::Vector2i(pos[0], pos[1]);



}

void Hero::move(sf::Vector2i dir) {
	this->position += dir;
}

void Hero::setTexture(const sf::Texture& texture) {
	this->texture = texture;
}

void Hero::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::Sprite heroSprite;
	const int TILE_SCALE = Settings::getTileScale();
	heroSprite.setTexture(this->texture);
	heroSprite.setScale(sf::Vector2f((float)TILE_SCALE, (float)TILE_SCALE));
	sf::Vector2f tempPos((float)position.x, (float)position.y);
	heroSprite.setPosition((float)Settings::getScaledTileSize() * tempPos);
	target.draw(heroSprite, states);

}

sf::Vector2i Hero::getPosition() {
	return this->position;
}

json Hero::serialize() {
	json hero;
	hero["position"] = { position.x , position.y };
	return hero;
}
