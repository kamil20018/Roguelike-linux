#pragma once

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Tile.h"

class AssetManager {
private:
	std::map<std::string, std::unique_ptr<sf::Texture>> textures;
	std::map<std::string, std::unique_ptr<sf::Font>> fonts;
	std::map<TileNames, Tile> tiles;
	std::map<TileNames, std::vector<std::string>> tileDecor;

public:
	AssetManager();
	~AssetManager();

	void AddTexture(std::string name, const std::string& filePath, bool wantRepeated = false);
	void AddTexture(std::string name, std::unique_ptr<sf::Texture> texture);


	void AddFont(std::string name, const std::string& filePath);
	void AddTile(TileNames name, Tile tile);
	void AddTileDecor(TileNames name, std::vector<std::string> tileDecor);


	const sf::Texture& GetTexture(std::string name) const;
	const sf::Font& GetFont(std::string name) const;
	Tile GetTile(TileNames name) const;
	std::vector<std::string> GetTileDecor(TileNames name) const;
};