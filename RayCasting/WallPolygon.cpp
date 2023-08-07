#include "WallPolygon.h"
#include "Config.h"

part::WallPolygon::WallPolygon(std::vector<sf::Vector2f> points) {
	this->points.clear();
	for (sf::Vector2f point : points) {
		this->points.push_back(point);
		this->points.back().color = config::color::dark_green;
	}
}


void part::WallPolygon::drawOnMiniMap(MiniMap* mini_map) {


	sf::RenderTexture* render_texture = mini_map->getRenderTexture();

	std::vector<sf::Vertex> rel_points;

	for (sf::Vertex &point : points) {
		sf::Vertex rel_point{mini_map->getRealativePosition(point.position), point.color};
		rel_points.push_back(rel_point);
	}

	render_texture->draw(&rel_points[0], points.size(), sf::LinesStrip);

}

RayCaster::Intersection* part::WallPolygon::getIntersection(RayCaster::Ray* ray) {
	// MEMORY LEAK WARNING
	RayCaster::Intersection* result_intersection = nullptr;
	
	for (int i = 0; i < points.size() - 1; ++i) {
		RayCaster::Intersection* cur_intersection = RayCaster::getRayLineIntersection(
			points[i].position, points[i + 1].position, ray);

		if (result_intersection == nullptr) {
			result_intersection = cur_intersection;
		} else if (cur_intersection != nullptr) {
			if (result_intersection->getDistance() > cur_intersection->getDistance()) {
				delete result_intersection;
				result_intersection = cur_intersection;
			} else {
				delete cur_intersection;
			}
		}
	}

	return result_intersection;

}
