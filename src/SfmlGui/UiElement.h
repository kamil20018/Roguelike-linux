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

            virtual void mouseMovement(sf::Vector2i mousePosition){};
            virtual void keyboardInput(sf::Keyboard::Key keyboardInput){};
            virtual bool wasClicked(sf::Vector2i mousePosition) = 0;            
        protected:

            UiElement() : isCurrentlyHeld(false){};

            bool isCurrentlyHeld;

        private:
            
    };
}