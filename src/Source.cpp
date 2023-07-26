#include "Game.h"
#include "Settings.h"
#include <SFML/Graphics.hpp>

//#include "json.hpp"
//#include <fstream>
//using json = nlohmann::json;



sf::Vector2i Settings::WINDOW_SIZE = sf::Vector2i(800, 600);
sf::Vector2i Settings::CHUNK_SIZE = sf::Vector2i(28, 21);
int Settings::TILE_SIZE = 32;
int Settings::TILE_SCALE = 2;
std::vector<long long> Settings::SEED = std::vector<long long>();

int main() {

    Settings::updateSettings();

    Game game;
    game.Run();

    return 0;
}