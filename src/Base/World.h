#pragma once
#include <unordered_map>
#include <unordered_set>

#include "TileChunk.h"
#include "Chunked.h"
#include "WorldGenerator.h"
#include <SFML/Graphics.hpp>

class World : public sf::Drawable, public Chunked<TileChunk> {

public:
	World(std::shared_ptr<Context> context);
	World(std::shared_ptr<Context> context, json saveData);
	/*std::vector<sf::Vector2i> getPath(sf::Vector2i begin, sf::Vector2i end, bool unitVector, bool withStart, bool withEnd);*/

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	json serialize();
private:
	bool removeUnloaded;
	std::shared_ptr<Context> context;
	WorldGenerator worldGenerator;
	int totalTiles, totalChunks;

	sf::Vector2f vecIntToFloat(sf::Vector2i vec);
	void updateLoadedChunks();

};
