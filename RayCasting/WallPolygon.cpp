#include "WallPolygon.h"
#include "Config.h"
#include "Functions.h"
#include <cmath>

part::WallPolygon::WallPolygon(std::vector<sf::Vector2f> points) {
	this->points.clear();
	length = 0;
	dist_before_point.push_back(0);
	for (sf::Vector2f point : points) {
		if (!this->points.empty()) {
			auto prev = this->points.back();
			length += Functions::get_dist({prev.position.x, prev.position.y}, {point.x, point.y});
			dist_before_point.push_back(length);
		}
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
	RayCaster::Intersection* result_intersection = nullptr;
	int point1_i = -1, point2_i = -1;


	for (int i = 0; i < points.size() - 1; ++i) {
		RayCaster::Intersection* cur_intersection = RayCaster::getRayLineIntersection(
			points[i].position, points[i + 1].position, ray);
		if (result_intersection == nullptr) {
			result_intersection = cur_intersection;
			point1_i = i;
			point2_i = i + 1;
		} else if (cur_intersection != nullptr) {
			if (result_intersection->getDistance() > cur_intersection->getDistance()) {
				delete result_intersection;
				result_intersection = cur_intersection;
				point1_i = i;
				point2_i = i + 1;
			} else {
				delete cur_intersection;
			}
		}
	}

	if (result_intersection != nullptr) {
		float dist_left = dist_before_point[point1_i]; // считаем дистанциюот начала до точки p1
		float dist_seg = Functions::get_dist({ points[point1_i].position.x, points[point1_i].position.y },
			result_intersection->position); // считаем дистанцию от p1 до точки пересечения
		float fraction = (dist_left + dist_seg); // FIXME
		result_intersection->part_of_object = fraction;
	}

	return result_intersection;

}
