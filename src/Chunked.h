#pragma once

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include <unordered_map>
#include <unordered_set>
#include "VectorHash.h"



template<class chunkedItem>
class Chunked {
public:
	void heroMoved(sf::Vector2i globalPos);
	bool isTraversable(sf::Vector2i globalPos);
protected:
	std::unordered_map<sf::Vector2i, chunkedItem> chunks;
	std::unordered_set<sf::Vector2i> loadedChunks;
	sf::Vector2i centreChunk;

	sf::Vector2i globalPosToChunk(sf::Vector2i position);

	virtual void updateLoadedChunks() = 0;
};


template<class chunkedItem>
bool Chunked<chunkedItem>::isTraversable(sf::Vector2i globalPos) {
	sf::Vector2i chunkPos = globalPosToChunk(globalPos);
	if (loadedChunks.find(chunkPos) == loadedChunks.end()) return false;

	return chunks.at(chunkPos).isTraversable(globalPos);
}


template<class chunkedItem>
void Chunked<chunkedItem>::heroMoved(sf::Vector2i globalPos) {
	sf::Vector2i newChunk = globalPosToChunk(globalPos);
	if (newChunk != centreChunk) {
		centreChunk = newChunk;
		updateLoadedChunks();
	}
}


template<class chunkedItem>
sf::Vector2i Chunked<chunkedItem>::globalPosToChunk(sf::Vector2i position) {
	int chunkWidth = Settings::getChunkSize().x;
	int chunkHeight = Settings::getChunkSize().y;
	int x = 0;
	int y = 0;
	if (position.x >= 0) {
		x = position.x / chunkWidth;
	}
	else {
		x = (position.x + 1) / chunkWidth - 1;
	}

	if (position.y >= 0) {
		y = position.y / chunkHeight;
	}
	else {
		y = (position.y + 1) / chunkHeight - 1;
	}
	return sf::Vector2i(x, y);
}
