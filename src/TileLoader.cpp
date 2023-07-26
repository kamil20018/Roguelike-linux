#include "TileLoader.h"

void TileLoader::loadTilesToContext(std::shared_ptr<Context>& context) {

    std::ifstream reader("../src/Tiles.json");
    json j;
    reader >> j;
    reader.close();

    std::unordered_map<TileNames, sf::Texture> tileTextureMap;
    std::unordered_map<DecorTiles, sf::Texture> decorTextureMap;

    for (const auto& tile : j) {
        std::string tileTexturePath = "../Resources/Textures/Tiles/";
        tileTexturePath.append(tile["file"]);
        sf::Texture texture;
        texture.loadFromFile(tileTexturePath);
        tileTextureMap.insert({ tileString.at(tile["name"]), texture });

        std::string decorTexturePath = "../Resources/Textures/Decorations/";
        auto jsonDecors = tile["decorations"];
        std::vector < std::string > decors;

        for (auto decora : jsonDecors.items()) {
            std::string decor = decora.key();

            decors.push_back(decor);
            std::string tempPath = decorTexturePath;
            tempPath.append(decor);


            sf::Texture texture;
            texture.loadFromFile(tempPath);

            decorTextureMap.insert({ decorString.at(decor), std::move(texture) });


            context->assets->AddTexture(decor, tempPath);
        }

        context->assets->AddTileDecor(tileString.at(tile["name"]), decors);
        Tile newTile(tile);
        context->assets->AddTile(tileString.at(tile["name"]), newTile);

    }

    //generating the texture sheet for tiles

    sf::RenderTexture tileSetTexture;
    int tileCount = j.size();
    int tileSize = Settings::getTileSize();
    int width = 4;
    tileSetTexture.create(width * tileSize, (tileCount / width + 1) * tileSize);

    for (int i = 0; i < tileTextureMap.size(); i++) {
        TileNames name = static_cast<TileNames>(i);
        sf::Texture tried = tileTextureMap[name];
        sf::Sprite tile;
        tile.setTexture(tried);
        tile.setPosition(sf::Vector2f(i % width * tileSize, i / width * tileSize));
        tileSetTexture.draw(tile);
    }

    tileSetTexture.display();
    std::unique_ptr<sf::Texture> tileSet = std::make_unique<sf::Texture>(tileSetTexture.getTexture());
    context->assets->AddTexture("tileSet", std::move(tileSet));


    //generating the texture sheet for decorations
    sf::Vector2i textureSize = generateDecorTexturePositions();
    sf::RenderTexture decorSetTexture;
    tileCount = decorTextureMap.size();
    tileSize = Settings::getTileSize();
    width = 4;
    decorSetTexture.create(textureSize.x * tileSize, textureSize.y * tileSize);

    for (int i = 0; i < decorTextureMap.size(); i++) {
        DecorTiles name = static_cast<DecorTiles>(i);
        sf::Texture tried = decorTextureMap[name];
        sf::Sprite tile;
        tile.setTexture(tried);
        sf::Vector2i tilePos = decorTexturePos[name];
        tile.setPosition(sf::Vector2f(tilePos.x * tileSize, tilePos.y * tileSize));
        decorSetTexture.draw(tile);
    }

    decorSetTexture.display();
    std::unique_ptr<sf::Texture> decorSet = std::make_unique<sf::Texture>(decorSetTexture.getTexture());
    context->assets->AddTexture("decorSet", std::move(decorSet));
}

sf::Vector2i TileLoader::generateDecorTexturePositions() {
    std::vector<std::pair<DecorTiles, sf::Vector2i>> decorSizeVector;

    for (auto& decor : decorSize) {
        decorSizeVector.push_back(std::make_pair( decor.first, decor.second ));
    }

    std::sort(decorSizeVector.begin(), decorSizeVector.end(),
    [](const std::pair<DecorTiles, sf::Vector2i>& a, const std::pair<DecorTiles, sf::Vector2i>& b) {
        return a.second.x * a.second.y > b.second.x * b.second.y;
    }
             );


    auto fits = [](int x, int y, sf::Vector2i size, std::vector<std::vector<bool>> occupied) {
        try {
            for (int i = x; i < x + size.x; i++) {
                for (int j = y; j < y + size.y; j++) {
                    if (occupied.at(j).at(i)) {
                        return false;
                    }
                }
            }
        } catch (const std::out_of_range& e) {
            return false;
        }

        return true;
    };


    int area = 0;

    for (auto size: decorSizeVector) {
        area += size.second.x * size.second.y;
    }


    int width = (int)(std::sqrt(area) * 1.3);
    int height = width;
    std::vector<std::vector<bool>> occupied = std::vector<std::vector<bool>>(height, std::vector<bool>(width, false));

    for (auto decorSize : decorSizeVector) {
        auto size = decorSize.second;

        bool fit = false;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (fits(j, i, size, occupied)) {
                    for (int k = i; k < i + size.y; k++) {
                        for (int l = j; l < j + size.x; l++) {
                            occupied.at(k).at(l) = true;
                        }
                    }

                    fit = true;
                    decorTexturePos.insert({ decorSize.first, sf::Vector2i(j, i) });
                    break;
                }
            }

            if (fit) {
                break;
            }
        }
    }

    return sf::Vector2i(width, width);
}
