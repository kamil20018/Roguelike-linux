#pragma once

#include "UiTestState.h"
#include "Game.h"
#include "State.h"
#include <memory>
#include "MapParser.h"
#include <iterator>
#include "Hero.h"
//#include "PerlinNoise.h"
#include "TextField.h"
#include "TextField2.h"
#include "Window.h"
#include "Slider.h"
#include "InputField.h"
#include "ClickState.h"
#include <optional>
struct Context;

class UiTestState : public State {
    public:
        UiTestState(std::shared_ptr<Context> &context);
        ~UiTestState();
        void Init() override;
        void ProcessInput() override;
        void Update() override;
        void Draw() override;
    private:
        std::shared_ptr<Context> context;

        sf::Vector2i mousePosition;
        std::optional<char> currText;
        std::shared_ptr<int> sliderValue;
        std::shared_ptr<std::string> textInField;
        std::vector<std::unique_ptr<sfui::UiElement>> UiElements;
};