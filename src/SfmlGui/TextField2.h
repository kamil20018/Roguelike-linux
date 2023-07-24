#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class TextField2 {
public:
	TextField2(std::string text);
private:
	std::string text;
	void processText();
};

