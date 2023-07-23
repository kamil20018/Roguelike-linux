#include "Tile.h"

Tile::Tile(json j) : isTraversable(j["isTraversable"]), name(j["name"]) {
	for (auto decoration : j["decorations"].items()) {
		this->possibleDecorations.push_back(decoration.key());
	}
}



bool Tile::getTraversable() {
	return this->isTraversable;
}

const std::vector<std::string>& Tile::getPossibleDecorations() {
	return possibleDecorations;
}

std::string Tile::getName() {
	return this->name;
}

void Tile::print() {
	std::cout << this->name << ", " << this->isTraversable << std::endl;
}