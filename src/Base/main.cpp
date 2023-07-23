#include <iostream>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

int main() {
    std::ifstream reader("Settings.json");
    std::cout << reader.rdbuf();
    std::cout << reader.tellg() << std::endl;
    reader.seekg(0, std::ios::beg);
    json j;
	reader >> j;
	reader.close();
    std::cout << j["tileSize"] << std::endl;
}