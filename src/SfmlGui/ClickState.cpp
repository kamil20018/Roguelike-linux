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
    //mouse hold changed state can be true only for a single frame, we need to enforce that by calling this method at the end of a frame;
    mouseHoldChanged = false;    
}
