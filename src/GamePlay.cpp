#include "GamePlay.h"

GamePlay::GamePlay(std::shared_ptr<Context> context, bool load) : context(context), mouseScrollDelta(0),
    mouseButtonDown(false), keyPressed(false), zoomFactor(1.0f), passTurn(false)

{

    _assets->AddTexture("hero", "../Resources/Textures/Hero/Hero.png");

    gameplayView = _window->getDefaultView();
    _window->setView(gameplayView);
    tileSize = Settings::getScaledTileSize();

    mouseOutline.setSize(vecIntToFloat(sf::Vector2i(tileSize, tileSize)));
    mouseOutline.setFillColor(sf::Color(0, 0, 0, 0));
    mouseOutline.setOutlineColor(sf::Color(255, 255, 0));
    mouseOutline.setOutlineThickness(5.0f);

    if (load) {
        loadGameInit();
    } else {
        newGameInit();
    }

}

void GamePlay::newGameInit() {

    float center = Settings::getScaledTileSize() / 2.0f;
    gameplayView.setCenter(sf::Vector2f(center, center));



    world = std::make_shared<World>(context);
    hero = std::make_unique<Hero>(_assets->GetTexture("hero"));
    actorManager = std::make_unique<ActorManager>(context, world);
}

void GamePlay::loadGameInit() {
    std::ifstream reader("../src/Save.json");
    json saveFile;
    reader >> saveFile;
    reader.close();

    json gamePlay = saveFile["gamePlay"];
    json viewPos = gamePlay["gameViewPos"];
    gameplayView.setCenter(sf::Vector2f(viewPos[0], viewPos[1]));
    zoomFactor = gamePlay["zoomFactor"];
    gameplayView.zoom(zoomFactor);


    world = std::make_shared<World>(context, saveFile["world"]);
    hero = std::make_unique<Hero>(_assets->GetTexture("hero"), saveFile["hero"]);
    actorManager = std::make_unique<ActorManager>(context, world, saveFile["actorManager"]);
}


void GamePlay::Init() {
    float size = 10.0;

    std::string message = "Destination is unreachable,\n or the path is too long.";
    TextField field(message, sf::Vector2f(120.0f, 120.0f), _assets->GetFont("pixel_font"), true);
    field.setBackgroundColor(sf::Color(0, 0, 255));
    field.setFontColor(sf::Color(255, 255, 255));
    field.setScalingBoundsSize(sf::Vector2f(50.0f, 50.0f));
    this->notification = field;
}

void GamePlay::ProcessInput() {
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window->close();
        } else if (event.type == sf::Event::KeyPressed) {
            keyPressed = true;

            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    saveGame();
                    _window->close();
                    break;

                case sf::Keyboard::Numpad7:
                    moveDir = sf::Vector2i(-1, -1);
                    break;

                case sf::Keyboard::Numpad8:
                case sf::Keyboard::W:
                    moveDir = sf::Vector2i(0, -1);
                    break;

                case sf::Keyboard::Numpad9:
                    moveDir = sf::Vector2i(1, -1);
                    break;

                case sf::Keyboard::Numpad1:
                    moveDir = sf::Vector2i(-1, 1);
                    break;

                case sf::Keyboard::Numpad2:
                case sf::Keyboard::S:
                    moveDir = sf::Vector2i(0, 1);
                    break;

                case sf::Keyboard::Numpad3:
                    moveDir = sf::Vector2i(1, 1);
                    break;

                case sf::Keyboard::Numpad4:
                case sf::Keyboard::A:
                    moveDir = sf::Vector2i(-1, 0);
                    break;

                case sf::Keyboard::Numpad6:
                case sf::Keyboard::D:
                    moveDir = sf::Vector2i(1, 0);
                    break;

                case sf::Keyboard::Add:
                    gameplayView.zoom(0.9f);
                    break;

                case sf::Keyboard::Subtract:
                    gameplayView.zoom(1.1f);
                    break;

                case sf::Keyboard::Space:
                    passTurn = true;
                    break;
            }
        } else if (event.type == sf::Event::MouseWheelMoved) {
            this->mouseScrollDelta = event.mouseWheel.delta;
        } else if (event.type == sf::Event::MouseButtonPressed) {
            this->mouseButtonDown = true;
        }

    }
}

void GamePlay::Update() {

    positionMouseOutline();

    if (mouseScrollDelta != 0) {
        zoomView();
    }

    onClickMovement();

    if (passTurn) {
        enemyTurn();
        passTurn = false;
        return;
    }

    if (moveDir != sf::Vector2i(0, 0)) {
        if (moveHero()) {
            enemyTurn();
        }
    }
}


void GamePlay::positionMouseOutline() {
    sf::Vector2i pixelPos = sf::Mouse::getPosition(*_window);
    sf::Vector2f worldPos = _window->mapPixelToCoords(pixelPos);
    mouseTilePos = sf::Vector2i((int)floor(worldPos.x / tileSize), (int)floor(worldPos.y / tileSize));
    mouseOutline.setPosition(vecIntToFloat(mouseTilePos * tileSize));
}

void GamePlay::zoomView() {
    if (mouseScrollDelta > 0) {
        zoomFactor *= 0.9f;
        gameplayView.zoom(0.9f);
    } else if (mouseScrollDelta < 0) {
        zoomFactor *= 1.1f;
        gameplayView.zoom(1.1f);
    }

    mouseScrollDelta = 0;
}

bool GamePlay::moveHero() {
    sf::Vector2i heroDestination = hero->getPosition() + moveDir;

    if (!world->isTraversable(heroDestination) || !actorManager->isTraversable(heroDestination)) { //
        std::cout << "destination unreachable" << std::endl;
        moveDir = sf::Vector2i(0, 0);
        return false;
    }

    hero->move(moveDir);
    //moves view along with hero
    gameplayView.move((float)Settings::getScaledTileSize() * vecIntToFloat(moveDir));
    world->heroMoved(heroDestination);
    actorManager->heroMoved(heroDestination);
    moveDir = sf::Vector2i(0, 0);
    return true;
}

void GamePlay::onClickMovement() {
    if (mouseButtonDown) {
        mouseButtonDown = false;
        this->heroPath = getPath(hero->getPosition(), mouseTilePos, true, false, true);
    }

    if (heroPath.size() != 0) {
        moveDir = heroPath[0];
        heroPath.erase(heroPath.begin());
    }
}

void GamePlay::enemyTurn() {

    auto pathLen = [](sf::Vector2i pos1, sf::Vector2i pos2) {
        sf::Vector2i t = pos2 - pos1;
        t = sf::Vector2i(std::abs(t.x), std::abs(t.y));
        int x = std::abs(t.x);
        int y = std::abs(t.y);
        int high = std::max(x, y);
        int low = std::min(x, y);
        return (float)(high - low) + 1.4f * low;
    };

    this->activeEnemies = actorManager->getEnemies();

    for (auto enemy : activeEnemies) {
        if (enemy->getViewDistance() > pathLen(enemy->getPosition(), hero->getPosition())) {
            std::vector<sf::Vector2i> path = getPath(enemy->getPosition(), hero->getPosition(), true);

            if (path.size() > 0) {
                enemy->move(path[0]);
                actorManager->updateEnemyChunks();
            }
        }
    }
}



void GamePlay::Draw() {
    _window->clear(sf::Color(0, 0, 0));


    //draw on moved view
    _window->setView(this->gameplayView);
    _window->draw(*world);
    _window->draw(*hero);
    _window->draw(mouseOutline);
    //_window->draw(*enemyChunk);
    _window->draw(*actorManager);





    //draw on UI layer
    _window->setView(this->UiView);

    sf::Text text;
    text.setFont(context->assets->GetFont("pixel_font"));
    //text.setString(std::format("x: {}, y: {}", mouseTilePos.x, mouseTilePos.y));
    _window->draw(text);
    //_window->draw(this->notification);
    _window->display();
    _window->setView(this->gameplayView);


}

void GamePlay::saveGame() {

    json saveFile;

    saveFile["gamePlay"] = serialize();
    saveFile["hero"] = hero->serialize();
    saveFile["world"] = world->serialize();
    saveFile["actorManager"] = actorManager->serialize();
    std::ofstream file("Save.json"); //loading the json object into a file
    file << std::setw(4) << saveFile;
    file.close();
}

json GamePlay::serialize() {
    sf::Vector2f gameViewPos = gameplayView.getCenter();
    json gamePlay;
    gamePlay["gameViewPos"] = { gameViewPos.x, gameViewPos.y };
    gamePlay["zoomFactor"] = zoomFactor;
    return gamePlay;
}




sf::Vector2f GamePlay::vecIntToFloat(sf::Vector2i vec) {
    return sf::Vector2f((float)vec.x, (float)vec.y);
}

std::vector<sf::Vector2i> GamePlay::getPath(sf::Vector2i begin, sf::Vector2i end, bool unitVector, bool withStart, bool withEnd) {

    const int ITERATIONS_CAP = 20000;

    auto calcHCost = [](sf::Vector2i currNode, sf::Vector2i endNode) {
        sf::Vector2i t = endNode - currNode;
        t = sf::Vector2i(std::abs(t.x), std::abs(t.y));
        int high = std::max(t.x, t.y);
        return high * 10;
    };

    auto dirCost = [](sf::Vector2i dir) {
        if (std::abs(dir.x) + std::abs(dir.y) > 1) {
            return 14; // cost of going diagonally
        }

        return 10; // cost of going vertically or horizontally
    };

    std::unordered_map<sf::Vector2i, Node> openMap;
    std::unordered_map<sf::Vector2i, Node> closedMap;
    std::unordered_map<sf::Vector2i, sf::Vector2i> cameFrom;

    std::vector<sf::Vector2i> dirs{ sf::Vector2i(1, 1), sf::Vector2i(1, 0), sf::Vector2i(1, -1), sf::Vector2i(0, 1), sf::Vector2i(0, -1),
                                    sf::Vector2i(-1, -1), sf::Vector2i(-1, 0), sf::Vector2i(-1, 1) };
    bool run = true;

    Node current(begin, 0, 0);
    openMap.insert({ current.position, current });

    int iterations = 0;

    while (!openMap.empty()) {
        current = openMap.begin()->second;

        for (const auto& pair : openMap) {
            if (pair.second < current) {
                current = pair.second;
            }
        }

        openMap.erase(current.position);

        closedMap.insert({ current.position, current });

        if (current.position == end) {
            break;
        }

        for (sf::Vector2i dir : dirs) {
            sf::Vector2i pos = current.position + dir;

            if (world->isTraversable(pos) and actorManager->isTraversable(pos) and !closedMap.contains(pos)) {
                if (!openMap.contains(pos)) {
                    Node newNode(pos, current.g_val + dirCost(dir), calcHCost(pos, end));
                    newNode.parentPos = current.position;
                    openMap.insert({ pos, newNode });
                } else {
                    int newGVal = current.g_val + dirCost(dir);

                    if (openMap.at(pos).g_val > newGVal) {
                        openMap.at(pos).g_val = newGVal;
                        openMap.at(pos).f_val = openMap.at(pos).h_val + newGVal;
                        openMap.at(pos).parentPos = current.position;
                    }
                }
            }

        }

        iterations++;

        if (iterations > ITERATIONS_CAP) {
            std::cout << "destination unreachable, or path too long" << std::endl;
            return std::vector<sf::Vector2i>();
        }
    }

    if (current.position != end) {
        std::cout << "destination unreachable" << std::endl;
        return std::vector<sf::Vector2i>();
    }

    std::vector<sf::Vector2i> path;
    sf::Vector2i tempPos = current.parentPos;

    while (tempPos != begin) {
        path.insert(path.begin(), tempPos);
        tempPos = closedMap.at(tempPos).parentPos;
    }

    if (withStart) {
        path.insert(path.begin(), begin);
    }

    if (withEnd) {
        path.push_back(end);
    }


    if (unitVector and path.size() > 0) {

        if (path.size() == 1) {
            path[0] -= begin;
            return path;
        }

        std::vector<sf::Vector2i> tempPath;

        for (int i = 0; i < path.size() - 1; i++) {
            tempPath.push_back(path[i + 1] - path[i]);
        }

        tempPath.insert(tempPath.begin(), path[0] - begin);
        path = tempPath;
    }


    return path;
}

