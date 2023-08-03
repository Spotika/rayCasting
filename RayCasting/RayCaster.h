#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "AbstractLevelPart.h"

class RayCaster {
public:
	/// <summary>
	/// класс луча
	/// </summary>
	class Ray {
	public:
		/// <summary>
		/// точка испускания луча
		/// </summary>
		sf::Vector2<int> start_point;
		/// <summary>
		/// Угол повогота в радианах относительно востока
		/// </summary>
		double orientation;
	};

	class Intersection {
	public:
		Ray* ray;
		sf::Vector2<int> position;

		bool operator < (Intersection const& other) const;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Возвращает дистанцию между точкой пересечения и началом луча</returns>
		double getDistance() const;
	};

	/// <summary>
	/// Создает пучок лучей
	/// </summary>
	/// <param name="start_point">Точка испускания лучей</param>
	/// <param name="num_of_rays">Количество лучей</param>
	/// <param name="orientation">Направление ценрального луча: угол в радианах относительно востока</param>
	/// <param name="fov">Угол распростронения лучей относительно orientation</param>
	void cast(sf::Vector2<int> start_point, int num_of_rays, double orientation, double fov);

	/// <summary>
	/// Получает пересечения с объектами
	/// </summary>
	/// <param name="level_parts">Ссылка на вектор объектов уровня</param>
	/// <returns>Возвращает список пересечений</returns>
	std::vector<Intersection>& getInstersections(std::vector<AbstractLevelPart*>& level_parts);
private:
	std::vector<Ray*> rays;
};