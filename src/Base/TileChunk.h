#pragma once
#include "Game.h"
#include "Tile.h"
#include <unordered_set>
#include <random>
#include "Settings.h"
#include "PerlinNoise.h"
class TileChunk : public sf::Drawable {
public:
	TileChunk(sf::Vector2i pos, std::vector<std::vector<TileNames>> tiles, std::shared_ptr<Context> context);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool isTraversable(sf::Vector2i pos);
private:
	int chunkSpacing; // adds a "border" to chunks (for debug purposes)
	std::shared_ptr<Context> context;
	std::vector<std::vector<TileNames>> tiles;
	std::vector<std::pair<DecorTiles, sf::Vector2i>> decorations;
	sf::Vector2i position;
	sf::Vector2i globalPosToLocal(sf::Vector2i pos);
	sf::Vector2i size;
	float tileSize;
	sf::Vector2f vecIntToFloat(sf::Vector2i vec) const;

	PerlinNoise noise;

	void generateDecorations(float density);

	const sf::Texture* tileSet;
	sf::VertexArray tileVertices;

	const sf::Texture* decorSet;
	sf::VertexArray decorVertices;
};
