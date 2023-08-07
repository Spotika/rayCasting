#include "Wall.h"
#include "Config.h"
#include <iostream>

part::Wall::Wall(sf::Vector2f first_point, sf::Vector2f second_point) : WallPolygon({ first_point, second_point }) {
}

void part::Wall::drawOnMiniMap(MiniMap* mini_map) {
	part::WallPolygon::drawOnMiniMap(mini_map);
}

RayCaster::Intersection* part::Wall::getIntersection(RayCaster::Ray* ray) {
	return part::WallPolygon::getIntersection(ray);
}
