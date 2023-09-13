#pragma once
#include <SFML/Graphics.hpp>
namespace sfui {
    class UiElement : public sf::Drawable {
        public: 
        
            virtual bool isActive() {
                return isCurrentlyHeld;    
            }

            virtual void mousePressed() {
                isCurrentlyHeld = true;    
            }

            void mouseReleased() {
                isCurrentlyHeld = false;    
            }

            virtual void mouseMovement(sf::Vector2i mousePosition){};
            virtual void textEntered(char text){};
            virtual bool wasClicked(sf::Vector2i mousePosition) = 0;            
        protected:

            UiElement() : isCurrentlyHeld(false){};

            bool isCurrentlyHeld;

        private:
            
    };
}