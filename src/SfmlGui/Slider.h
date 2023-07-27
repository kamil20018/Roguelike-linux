#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>

namespace sfui {
    template<typename T>
    class Slider : public sf::Drawable {
        public:
            Slider();
            Slider(sf::Vector2f size, sf::Vector2f position, T minValue, T maxValue);
            void setBarSize(sf::Vector2f size);
            void setBarColor(sf::Color color);
            void setBarOutline(sf::Color color, float thickness);
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            bool wasClicked(sf::Vector2i mousePosition);
            void mousePressed();
            void mouseReleased();
            bool isActive();
            void update(sf::Vector2i mousePosition);
            T getValue();
        private:
            //slider params
            sf::Color color;
            sf::RectangleShape slider;

            //movable bar params
            float barPostion;
            sf::RectangleShape bar;
           
            //mouse info
            bool isCurrentlyHeld;

            //value range
            T minValue;
            T maxValue;
            T currValue;
    };
}

template<typename T> sfui::Slider<T>::Slider() : isCurrentlyHeld(false) {}

template<typename T> sfui::Slider<T>::Slider(sf::Vector2f size, sf::Vector2f position, T minValue, T maxValue) 
        : isCurrentlyHeld(false)
        , minValue(minValue)
        , maxValue(maxValue) 
        , currValue(minValue) {
    slider.setFillColor(sf::Color::White);
    slider.setSize(size);
    slider.setPosition(position);
}

template<typename T>
void sfui::Slider<T>::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(slider);
    target.draw(bar);
}

template<typename T>
void sfui::Slider<T>::setBarSize(sf::Vector2f size) {
    sf::Vector2f sliderSize = slider.getSize();
    sf::Vector2f sliderPosition = slider.getPosition();
    bar.setSize(size);
    bar.setPosition(sf::Vector2f(
        sliderPosition.x - size.x / 2.0f,
        sliderPosition.y - size.y / 2.0f + sliderSize.y / 2.0f
    ));
}

template<typename T>
void sfui::Slider<T>::setBarColor(sf::Color color) {
    bar.setFillColor(color);
}

template<typename T>
void sfui::Slider<T>::setBarOutline(sf::Color color, float thickness) {
    bar.setOutlineColor(color);
    bar.setOutlineThickness(thickness);
}

template<typename T>
bool sfui::Slider<T>::wasClicked(sf::Vector2i mousePosition) {
    sf::Vector2f sliderPosition = slider.getPosition();
    sf::Vector2f sliderSize = slider.getSize();
    return sliderPosition.x < mousePosition.x &&
           mousePosition.x < sliderPosition.x + sliderSize.x &&
           sliderPosition.y < mousePosition.y &&
           mousePosition.y < sliderPosition.y + sliderSize.y;     
}

template<typename T>
bool sfui::Slider<T>::isActive() {
    return isCurrentlyHeld;    
}

template<typename T>
void sfui::Slider<T>::mousePressed() {
    isCurrentlyHeld = true;    
}

template<typename T>
void sfui::Slider<T>::mouseReleased() {
    isCurrentlyHeld = false;    
}

template<typename T>
void sfui::Slider<T>::update(sf::Vector2i mousePosition) {
    if(isCurrentlyHeld){

        sf::Vector2f barPosition = bar.getPosition();
        sf::Vector2f sliderPosition = slider.getPosition();

        if(sliderPosition.x > mousePosition.x){
            bar.setPosition(sf::Vector2f(sliderPosition.x, barPosition.y));
            return;
        }

        if(sliderPosition.x + slider.getSize().x < mousePosition.x){
            bar.setPosition(sf::Vector2f(sliderPosition.x + slider.getSize().x, barPosition.y));
            return;
        }

        bar.setPosition(sf::Vector2f(mousePosition.x, barPosition.y));

        currValue = minValue + (maxValue - minValue) / (slider.getSize().x / (bar.getPosition().x - slider.getPosition().x));
    }    
}

template<typename T>
T sfui::Slider<T>::getValue() {
    return currValue;  
}