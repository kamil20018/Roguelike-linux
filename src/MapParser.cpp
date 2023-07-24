#include "MapParser.h"

std::unordered_map<sf::Vector2i, Tile> MapParser::parseMap(std::shared_ptr<Context>& context, std::string fileName) {
	std::unordered_map<sf::Vector2i, Tile> output;

	std::ifstream reader(fileName);
	json j;
	reader >> j;
	reader.close();

	for (const auto& tileType : j) {
		std::string name = tileType["name"];
		Tile t = context->assets->GetTile(tileString.at(name));
		for (const auto& pos : tileType["positions"]) {
			sf::Vector2i position(pos[0], pos[1]);
			//t.setPosition(position);
			output.insert({ position, t });
			output.at(position).print();
		}
	}
	return output;
}
