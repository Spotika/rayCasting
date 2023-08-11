#include "Functions.h"
#include <cmath>

float Functions::get_dist(sf::Vector2f point1, sf::Vector2f point2) {
	return std::sqrt((point1.x - point2.x) * (point1.x - point2.x) +
		(point1.y - point2.y) * (point1.y - point2.y));
}