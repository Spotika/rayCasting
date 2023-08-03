#pragma once
#include "WallPolygon.h"

namespace part {

	class WallRect : public WallPolygon {

		/// <summary>
		/// 
		/// </summary>
		/// <param name="corner">���������� ����� ������� �����</param>
		/// <param name="width">������</param>
		/// <param name="height">������</param>
		WallRect(sf::Vector2<int> corner, int width, int height);

		void drawOnMiniMap(MiniMap* mini_map);
		RayCaster::Intersection getIntersection(RayCaster::Ray* ray);
	};

}