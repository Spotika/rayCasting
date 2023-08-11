#pragma once
#include "AbstractLevelPart.h"
#include <vector>
#include "IDrawableOnMiniMap.h"


namespace part {

	/// <summary>
	/// Ломаная из стен
	/// </summary>
	class WallPolygon : public AbstractLevelPart, public IDrawableOnMinimap {
	public:
		/// <summary>
		/// Длина стены
		/// </summary>
		float length;
		std::vector<float> dist_before_point;

		std::vector<sf::Vertex> points;

		WallPolygon(std::vector<sf::Vector2f> points);

		void drawOnMiniMap(MiniMap* mini_map);
		RayCaster::Intersection* getIntersection(RayCaster::Ray* ray);
	};
}