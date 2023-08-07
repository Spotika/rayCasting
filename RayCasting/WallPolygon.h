#pragma once
#include "AbstractLevelPart.h"
#include <vector>
#include "IDrawableOnMiniMap.h"


namespace part {

	/// <summary>
	/// Полигон стен
	/// </summary>
	class WallPolygon : public AbstractLevelPart, public IDrawableOnMinimap {
	public:
		std::vector<sf::Vertex> points;

		WallPolygon(std::vector<sf::Vector2f> points);

		void drawOnMiniMap(MiniMap* mini_map);
		RayCaster::Intersection* getIntersection(RayCaster::Ray* ray);
	};
}