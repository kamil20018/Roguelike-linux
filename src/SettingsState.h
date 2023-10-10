#include "Game.h"
#include "State.h"
#include <memory>
#include "TextField.h"
#include "Window.h"
#include "Slider.h"
#include "InputField.h"
#include "ClickState.h"
#include <optional>
struct Context;

class SettingsState : public State {
    public:
        SettingsState(std::shared_ptr<Context> &context);
        ~SettingsState();
        void Init() override;
        void ProcessInput() override;
        void Update() override;
        void Draw() override;
    private:
        std::shared_ptr<Context> context;
        std::vector<std::unique_ptr<sfui::UiElement>> UiElements;
        std::optional<char> currText;
        std::vector<sf::Text> optionTexts;
        sf::Vector2i mousePosition;

        std::shared_ptr<std::string> textWindowX;
        std::shared_ptr<std::string> textWindowY;
};