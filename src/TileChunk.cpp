#include "TileChunk.h"


TileChunk::TileChunk(sf::Vector2i pos, std::vector<std::vector<TileNames>> tiles, std::shared_ptr<Context> context) : context(context) {

	this->position = pos;
	this->tiles = tiles;
	size = Settings::getChunkSize();
	this->chunkSpacing = 10;

	generateDecorations(0.3f);


	this->tileSize = (float)Settings::getTileSize();
	sf::Vector2f offset = tileSize * sf::Vector2f((float)pos.x * size.x, (float)pos.y * size.y);
	this->tileSet = &context->assets->GetTexture("tileSet");
	tileVertices.setPrimitiveType(sf::Quads);
	tileVertices.resize(size.x * size.y * 4);

	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {

			int tileNumber = static_cast<int>(tiles[j][i]);

			int tu = tileNumber % (tileSet->getSize().x / (int)tileSize);
			int tv = tileNumber / (tileSet->getSize().x / (int)tileSize);

			sf::Vertex* quad = &tileVertices[(i + j * size.x) * 4];
			quad[0].position = sf::Vector2f(i * tileSize, j * tileSize) + offset;
			quad[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize) + offset;
			quad[2].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize) + offset;
			quad[3].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize) + offset;

			quad[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize, (tv + 1) * tileSize);
			quad[3].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);
		}
	}

	this->decorSet = &context->assets->GetTexture("decorSet");
	decorVertices.setPrimitiveType(sf::Quads);
	decorVertices.resize(decorations.size() * 4);
	int index = 0;
	for (std::pair<DecorTiles, sf::Vector2i> decorPos : decorations) {
		int decorNumber = static_cast<int>(decorPos.first);
		//int tu = decorNumber % (decorSet->getSize().x / (int)tileSize);
		//int tv = decorNumber / (decorSet->getSize().x / (int)tileSize);
		int tu = decorTexturePos[decorPos.first].x;
		int tv = decorTexturePos[decorPos.first].y;
		
		sf::Vector2i decorS = decorSize.at(decorPos.first);

		int i = decorPos.second.x;
		int j = decorPos.second.y;
		sf::Vertex* quad = &decorVertices[index * 4];
		quad[0].position = sf::Vector2f(i * tileSize, j * tileSize) + offset;
		quad[1].position = sf::Vector2f((i + decorS.x) * tileSize, j * tileSize) + offset;
		quad[2].position = sf::Vector2f((i + decorS.x) * tileSize, (j + decorS.y) * tileSize) + offset;
		quad[3].position = sf::Vector2f(i * tileSize, (j + decorS.y) * tileSize) + offset;

		quad[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
		quad[1].texCoords = sf::Vector2f((tu + decorS.x) * tileSize, tv * tileSize);
		quad[2].texCoords = sf::Vector2f((tu + decorS.x) * tileSize, (tv + decorS.y) * tileSize);
		quad[3].texCoords = sf::Vector2f(tu * tileSize, (tv + decorS.y) * tileSize);

		index++;
	}
}

void TileChunk::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.texture = tileSet;
	target.draw(tileVertices, states);

	states.texture = decorSet;
	target.draw(decorVertices, states);
}


bool TileChunk::isTraversable(sf::Vector2i pos) {
	sf::Vector2i localPos = globalPosToLocal(pos);
	return _assets->GetTile(tiles[localPos.y][localPos.x]).getTraversable();
}

sf::Vector2i TileChunk::globalPosToLocal(sf::Vector2i pos) {
	int chunkWidth = Settings::getChunkSize().x;
	int chunkHeight = Settings::getChunkSize().y;
	int x = 0;
	int y = 0;
	if (pos.x >= 0) {
		x = pos.x % chunkWidth;
	}
	else {
		x = ((-pos.x - 1) / chunkWidth + 1) * chunkWidth + pos.x;
	}

	if (pos.y >= 0) {
		y = pos.y % chunkHeight;
	}
	else {
		y = ((-pos.y - 1) / chunkHeight + 1) * chunkHeight + pos.y;
	}
	return sf::Vector2i(x, y);
}

sf::Vector2f TileChunk::vecIntToFloat(sf::Vector2i vec) const {
	return sf::Vector2f((float)vec.x, (float)vec.y);
}

void TileChunk::generateDecorations(float density) {
	int decorationCount = (int)(size.x * size.y * density);
	std::unordered_set<sf::Vector2i> positions;

	for (int i = 0; i < decorationCount; i++) {
		positions.insert(std::move(noise.randomPos(sf::Vector2i(i, i), size)));
	}

	int index = 0;
	for (sf::Vector2i pos : positions) {

		TileNames tile = tiles[pos.y][pos.x];

		std::vector<std::string> decors = _assets->GetTile(tile).getPossibleDecorations();

		float nois = noise.perl(position.x * size.x + pos.x + 0.5f, position.y * size.y + pos.y + 0.5f);

		int decorSize = (int)decors.size();

		if (decorSize == 1) {
			decorations.push_back({ decorString.at(decors[0]), pos });
		}
		else if (decorSize > 1) {
			decorations.push_back({ decorString.at(decors[index % decorSize]), pos });
		}
		index++;
	}

	std::sort(decorations.begin(), decorations.end(),
			[](const std::pair<DecorTiles, sf::Vector2i>& dec1, const std::pair <DecorTiles, sf::Vector2i>& dec2) {
				return dec1.second.y < dec2.second.y;
			}
	);

}