#pragma once
#include <SFML/Graphics.hpp>
namespace sfui {
    class UiElement : public sf::Drawable {
        public: 
        
            bool isActive() {
                return isCurrentlyHeld;    
            }

            void mousePressed() {
                isCurrentlyHeld = true;    
            }

            void mouseReleased() {
                isCurrentlyHeld = false;    
            }

        protected:

            UiElement() : isCurrentlyHeld(false){};

            bool isCurrentlyHeld;

        private:
            
    };
}