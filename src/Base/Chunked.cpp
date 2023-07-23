#include "Chunked.h"




//template void Chunked<TileChunk>::heroMoved(sf::Vector2i globalPos);
//template void Chunked<EnemyChunk>::heroMoved(sf::Vector2i globalPos);


//
//template sf::Vector2i Chunked<TileChunk>::globalPosToChunk(sf::Vector2i position);
//template sf::Vector2i Chunked<EnemyChunk>::globalPosToChunk(sf::Vector2i position);



//template<class chunkedItem>
//void Chunked<chunkedItem>::heroMoved(sf::Vector2i globalPos) {
//	sf::Vector2i newChunk = globalPosToChunk(globalPos);
//	if (newChunk != centreChunk) {
//		centreChunk = newChunk;
//		updateLoadedChunks();
//	}
//}
//
//
//template<class chunkedItem>
//sf::Vector2i Chunked<chunkedItem>::globalPosToChunk(sf::Vector2i position) {
//	int chunkWidth = Settings::getChunkSize().x;
//	int chunkHeight = Settings::getChunkSize().y;
//	int x = 0;
//	int y = 0;
//	if (position.x >= 0) {
//		x = position.x / chunkWidth;
//	}
//	else {
//		x = (position.x + 1) / chunkWidth - 1;
//	}
//
//	if (position.y >= 0) {
//		y = position.y / chunkHeight;
//	}
//	else {
//		y = (position.y + 1) / chunkHeight - 1;
//	}
//	return sf::Vector2i(x, y);
//}