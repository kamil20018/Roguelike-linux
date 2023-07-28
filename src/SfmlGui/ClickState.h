#pragma once

namespace sfui {
    class ClickState {
        public:
            static void mouseButtonPressed();
            static void mouseButtonReleased();
            static bool justPressed();
            static bool justReleased();
            static bool holding();
            static void update();
        private:
            inline static bool mouseHold = false;
            inline static bool mouseHoldChanged = false;
    };
}