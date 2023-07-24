#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <unordered_map>
#include "VectorHash.h"
#include "Settings.h"
class PerlinNoise {
public:
	PerlinNoise();
	std::vector<sf::Vector2f> gradients;
	std::unordered_map<sf::Vector2i, sf::Vector2f> gradientPos;
	//void generateGradients();
	//void getGradVals(sf::Vector2i pos);
	float perl(float x, float y);
	sf::Vector2f randomGradient(sf::Vector2i pos);
	sf::Vector2i randomPos(sf::Vector2i pos, sf::Vector2i bounds);
	//---------------------------
private:

	int width, height;
	std::vector<long long> seed;
	std::vector<sf::Vector2i> dirs{
		sf::Vector2i(0, 0),
		sf::Vector2i(1, 0),
		sf::Vector2i(0, 1),
		sf::Vector2i(1, 1)
	};
	float dot(sf::Vector2f v1, sf::Vector2f v2);
	float fade(float x);
	sf::Vector2f toFloat(sf::Vector2i);
	//---------------------------
	float interpolate(float a0, float a1, float w);
};

