#include "RayCaster.h"
#include "AbstractLevelPart.h"
#include <iostream>
#include <numbers>
#include <cmath>

void RayCaster::cast(sf::Vector2f start_point, int num_of_rays, float orientation, float fov) {
	float rad_step = fov / num_of_rays;
	float rad_begin = orientation + (fov / 2);

	// Удаление предыдущих лучей
	for (std::vector<Ray*>::const_iterator iter = rays.begin(); iter != rays.end(); ++iter) {
		delete* iter;
	}

	rays.clear();

	for (int ray_num = 0; ray_num < num_of_rays; ++ray_num) {
		Ray* ray = new Ray(start_point, rad_begin - rad_step * ray_num, ray_num);
		rays.push_back(ray);
	}
}

std::vector<RayCaster::Intersection*> RayCaster::getInstersections(std::vector<AbstractLevelPart*>& level_parts) {


	std::vector<RayCaster::Intersection*> result;

	for (Ray* ray : rays) {
		Intersection* nearest_intersection = nullptr;

		for (AbstractLevelPart* part : level_parts) {
			Intersection* cur_intersection = part->getIntersection(ray);

			if (cur_intersection != nullptr) {
				if (nearest_intersection == nullptr) {
					nearest_intersection = cur_intersection;
				} else {
					if (nearest_intersection->getDistance() > cur_intersection->getDistance()) {
						delete nearest_intersection;
						nearest_intersection = cur_intersection;
					} else {
						delete cur_intersection;
					}
				}
			}
		}
		if (nearest_intersection != nullptr) {
			result.push_back(nearest_intersection);
		}
	}
	return result;
}

RayCaster::Intersection* RayCaster::getRayLineIntersection(sf::Vector2f first_point, sf::Vector2f second_point, Ray* ray) {
	float EPS = 1e-5;
	
	float (*det)(float a, float b, float c, float d) = [](float a, float b, float c, float d) {
		return a * d - b * c;
	};
	
	float A1, B1, C1, A2, B2, C2;
	float x1 = first_point.x, x2 = second_point.x, y1 = first_point.y, y2 = second_point.y;
	A1 = y2 - y1;
	B1 = x1 - x2;
	C1 = x1 * (y1 - y2) + y1 * (x2 - x1);


	x1 = ray->start_point.x;
	y1 = ray->start_point.y;
	float mod = 100;
	x2 = x1 + mod * std::cos(ray->orientation);
	y2 = y1 + mod * std::sin(ray->orientation);

	A2 = y2 - y1;
	B2 = x1 - x2;
	C2 = x1 * (y1 - y2) + y1 * (x2 - x1);

	float x, y;

	float zn = det(A1, B1, A2, B2);

	if (abs(zn) < EPS) {
		return nullptr;
	}

	x = -det(C1, B1, C2, B2) / zn;
	y = - det(A1, C1, A2, C2) / zn;

	if (first_point.x - EPS <= x && x <= second_point.x + EPS || first_point.x + EPS >= x && x >= second_point.x - EPS) {
		if (first_point.y - EPS <= y && y <= second_point.y + EPS || first_point.y + EPS >= y && y >= second_point.y - EPS) {
			

			// принадлежность точки лучу
			if ((x - x1) * (x2 - x1) >= 0 && (y - y1) * (y2 - y1) >= 0) {
				return new Intersection(*ray, { x, y });
			}
		}
	}

	return nullptr;
}

float RayCaster::Intersection::getDistance() const {
	return std::sqrt(((ray.start_point.x - position.x) * (ray.start_point.x - position.x) +
		(ray.start_point.y - position.y) * (ray.start_point.y - position.y)));
}
