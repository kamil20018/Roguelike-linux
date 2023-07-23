#include "Enemy.h"

Enemy::Enemy(const sf::Texture& texture, sf::Vector2i position, int viewDistance, std::shared_ptr<World> world) : texture(&texture), position(position), world(world), viewDistance(viewDistance) {
}

Enemy::Enemy(const sf::Texture& texture, sf::Vector2i position, std::shared_ptr<World> world, json saveData) : texture(&texture), world(world) {
	json pos = saveData["position"];
	this->viewDistance = saveData["viewDistance"];
	this->position = sf::Vector2i(pos[0], pos[1]);
}

void Enemy::move(sf::Vector2i dir) {
	this->position += dir;
}

void Enemy::takeTurn(WorldData data) {
	std::vector<sf::Vector2i> unitVectors{
		sf::Vector2i(-1, 0),
		sf::Vector2i(1, 0),
		sf::Vector2i(-1, 1),
		sf::Vector2i(0, 1),
		sf::Vector2i(0, -1),
		sf::Vector2i(1, -1),
		sf::Vector2i(1, 1),
		sf::Vector2i(-1, -1)
	};

	std::random_device rd;
	std::mt19937 mt = std::mt19937(rd());
	std::uniform_int_distribution<int> moveDir = std::uniform_int_distribution<int>(0, unitVectors.size() - 1);

	sf::Vector2i dir = unitVectors[moveDir(mt)];
	sf::Vector2i destination = this->position + dir;
	if (world->isTraversable(destination)) {
		move(dir);
	}

}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::Sprite heroSprite;
	const int TILE_SCALE = Settings::getTileScale();
	heroSprite.setTexture(*this->texture);
	heroSprite.setScale(sf::Vector2f((float)TILE_SCALE, (float)TILE_SCALE));
	sf::Vector2f tempPos((float)position.x, (float)position.y);
	heroSprite.setPosition((float)Settings::getScaledTileSize() * tempPos);
	target.draw(heroSprite, states);
}

sf::Vector2i Enemy::getPosition() {
	return position;
}

int Enemy::getViewDistance() {
	return viewDistance;
}

json Enemy::serialize() {

	json enemy;
	enemy["position"] = { position.x, position.y };
	enemy["viewDistance"] = viewDistance;
	return enemy;
}
