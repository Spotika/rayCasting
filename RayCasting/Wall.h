#pragma once
#include "AbstractLevelPart.h"
#include "SFML/Graphics.hpp"

namespace part {
	
	class Wall : public AbstractLevelPart {
	public:
		/// <summary>
		/// Первая точка стены
		/// </summary>
		sf::Vector2<int> first_point;
		/// <summary>
		/// Вторая точка стены
		/// </summary>
		sf::Vector2<int> second_point;

		Wall(sf::Vector2<int> first_point, sf::Vector2<int> second_point);


		void drawOnMiniMap(MiniMap* mini_map);
		RayCaster::Intersection getIntersection(RayCaster::Ray* ray);
	};
}