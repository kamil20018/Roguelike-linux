#pragma once
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

using json = nlohmann::json;
class Settings {
    public:
        static sf::Vector2i getWindowSize();
        static int getTileSize();
        static int getTileScale();
        static int getScaledTileSize();
        static sf::Vector2i getChunkSize();
        static void updateSettings();
        static std::vector<long long> getSeed();

    private:
        //all of the settings will be overwritten by ones loaded from the settings.json file
        inline static sf::Vector2i WINDOW_SIZE = sf::Vector2i();
        inline static sf::Vector2i CHUNK_SIZE = sf::Vector2i();
        inline static int TILE_SIZE = 32;
        inline static int TILE_SCALE = 2;
        inline static std::vector<long long> SEED = std::vector<long long>();
};

