#pragma once
#include "AbstractLevelPart.h"
#include "Wall.h"
#include <vector>

namespace part {
	class WallPolygon : public AbstractLevelPart {
	public:
		std::vector<Wall*> walls;

		WallPolygon(std::vector<sf::Vector2<int>> points);

		void drawOnMiniMap(MiniMap* mini_map);
		RayCaster::Intersection getIntersection(RayCaster::Ray* ray);
	};
}