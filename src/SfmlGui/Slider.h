#pragma once
#include <algorithm>
#include <iostream>
#include "UiElement.h"
#include <memory>

namespace sfui {
    template<typename T>
    class Slider : public UiElement {
        public:
            Slider();
            Slider(sf::Vector2f size, sf::Vector2f position, T minValue, T maxValue, std::shared_ptr<T> value);
            void setBarSize(sf::Vector2f size);
            void setBarColor(sf::Color color);
            void setBarOutline(sf::Color color, float thickness);
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            
            void update(sf::Vector2i mousePosition);
            void mouseMovement(sf::Vector2i mousePosition) override;
            bool wasClicked(sf::Vector2i mousePosition);
            T getValue();
        private:
            //slider params
            sf::Color color;
            sf::RectangleShape slider;

            //movable bar params
            float barPostion;
            sf::RectangleShape bar;

            //value range
            T minValue;
            T maxValue;
            T currValue;
            std::shared_ptr<T> value;
    };
}

template<typename T> sfui::Slider<T>::Slider() : UiElement() {}

template<typename T> sfui::Slider<T>::Slider(sf::Vector2f size, sf::Vector2f position, T minValue, T maxValue, std::shared_ptr<T> value) 
        : UiElement()
        , minValue(minValue)
        , maxValue(maxValue) 
        , currValue(minValue)
        , value(value) {
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
        *value = currValue;
    }    
}

template<typename T>
void sfui::Slider<T>::mouseMovement(sf::Vector2i mousePosition) {
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
        *value = currValue;
    }    
}

template<typename T>
T sfui::Slider<T>::getValue() {
    return currValue;  
}