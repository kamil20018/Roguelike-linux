#include "ClickState.h"
void sfui::ClickState::mouseButtonPressed() {
    if(!mouseHold) {
        mouseHoldChanged = true;
    }

    mouseHold = true;    
}

void sfui::ClickState::mouseButtonReleased() {
    if(mouseHold) {
        mouseHoldChanged = true;
    }

    mouseHold = false;
}

bool sfui::ClickState::justPressed() {
    return mouseHold && mouseHoldChanged;
}

bool sfui::ClickState::justReleased() {
    return !mouseHold && mouseHoldChanged;
}

bool sfui::ClickState::holding() {
    return mouseHold;
}

void sfui::ClickState::update() {
    //needs to be called at the end of a frame to update the mouseHoldChanged state;
    mouseHoldChanged = false;    
}
