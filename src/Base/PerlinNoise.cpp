#include "PerlinNoise.h"
/* Function to linearly interpolate between a0 and a1
 * Weight w should be in the range [0.0, 1.0]
 */
float PerlinNoise::interpolate(float a0, float a1, float w) {
	return (a1 - a0) * w + a0;
}

float PerlinNoise::dot(sf::Vector2f v1, sf::Vector2f v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

float PerlinNoise::fade(float x) {
	return ((6 * x - 15) * x + 10) * x * x * x;
}

sf::Vector2f PerlinNoise::toFloat(sf::Vector2i v) {
	return sf::Vector2f((float)v.x, (float)v.y);
}

sf::Vector2f PerlinNoise::randomGradient(sf::Vector2i pos) {
	const unsigned w = 8 * sizeof(unsigned);
	const unsigned s = w / 2;
	unsigned a = pos.x, b = pos.y;
	a *= seed[0]; b ^= a << s | a >> w - s;
	b *= seed[1]; a ^= b << s | b >> w - s;
	a *= seed[2];

	float random = a * (3.14159265 / ~(~0u >> 1));
	sf::Vector2f v;
	v.x = cos(random); v.y = sin(random);
	return v;
}

sf::Vector2i PerlinNoise::randomPos(sf::Vector2i pos, sf::Vector2i bounds) {
	const unsigned w = 8 * sizeof(unsigned);
	const unsigned s = w / 2;
	unsigned a = pos.x, b = pos.y;
	a *= seed[0]; b ^= a << s | a >> w - s;
	b *= seed[1]; a ^= b << s | b >> w - s;
	a *= seed[2];

	sf::Vector2i v;
	v.x = a % bounds.x; v.y = b % bounds.y;
	return v;
}

float PerlinNoise::perl(float x, float y) {

	int posX = floor(x);
	int posY = floor(y);

	float xf = x - posX;
	float yf = y - posY;

	sf::Vector2i btmLeftPos(posX, posY);
	sf::Vector2i btmRightPos(posX + 1, posY);
	sf::Vector2i topLeftPos(posX, posY + 1);
	sf::Vector2i topRightPos(posX + 1, posY + 1);

	sf::Vector2f btmLeftVal = randomGradient(btmLeftPos);
	sf::Vector2f btmRightVal = randomGradient(btmRightPos);
	sf::Vector2f topLeftVal = randomGradient(topLeftPos);
	sf::Vector2f topRightVal = randomGradient(topRightPos);

	float v = fade(yf);

	return interpolate(
		interpolate(btmLeftVal.x * (x - btmLeftPos.x) + btmLeftVal.y * (y - btmLeftPos.y), topLeftVal.x * (x - topLeftPos.x) + topLeftVal.y * (y - topLeftPos.y), v),
		interpolate(btmRightVal.x * (x - btmRightPos.x) + btmRightVal.y * (y - btmRightPos.y), topRightVal.x * (x - topRightPos.x) + topRightVal.y * (y - topRightPos.y), v),
		fade(xf)
	);
}

PerlinNoise::PerlinNoise() {
	seed = Settings::getSeed();
}

