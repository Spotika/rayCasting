#pragma once
#include "AbstractLevelPart.h"
#include "SFML/Graphics.hpp"
#include "IDrawableOnMiniMap.h"
#include "WallPolygon.h"

namespace part {
	// одна стена
	class Wall : public WallPolygon {
	public:
		Wall(sf::Vector2f first_point, sf::Vector2f second_point);


		void drawOnMiniMap(MiniMap* mini_map);
		RayCaster::Intersection* getIntersection(RayCaster::Ray* ray);
	};
}