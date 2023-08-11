#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class AbstractLevelPart;

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
		sf::Vector2f start_point;
		/// <summary>
		/// Угол повогота в радианах относительно востока
		/// </summary>
		float orientation;
		/// <summary>
		/// номер луча при генерации
		/// </summary>
		int num;

		Ray(const sf::Vector2f& start_point, float orientation, int num=-1)
			: start_point(start_point), orientation(orientation), num(num) {}

		~Ray() {}
	};

	class Intersection {
	public:
		Ray ray;
		sf::Vector2f position;
		/// <summary>
		/// часть от начала на которую делит точка пересечения объект
		/// </summary>
		float part_of_object;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Возвращает дистанцию между точкой пересечения и началом луча</returns>
		float getDistance() const;

		Intersection(Ray ray, const sf::Vector2f& position) : ray(ray), position(position), part_of_object(0) {};

		~Intersection() {}
	};

	/// <summary>
	/// Создает пучок лучей
	/// </summary>
	/// <param name="start_point">Точка испускания лучей</param>
	/// <param name="num_of_rays">Количество лучей</param>
	/// <param name="orientation">Направление ценрального луча: угол в радианах относительно востока</param>
	/// <param name="fov">Угол распростронения лучей относительно orientation</param>
	void cast(sf::Vector2f start_point, int num_of_rays, float orientation, float fov);

	/// <summary>
	/// Получает пересечения с объектами
	/// </summary>
	/// <param name="level_parts">Ссылка на вектор объектов уровня</param>
	/// <returns>Возвращает список пересечений</returns>
	std::vector<Intersection*> getInstersections(std::vector<AbstractLevelPart*>& level_parts);

	/// <summary>
	/// Возвращает пересечение луча с отрезком
	/// Нужно удалить пересечение после использования
	/// </summary>
	/// <param name="first_point"></param>
	/// <param name="second_point"></param>
	/// <param name="ray"></param>
	/// <returns></returns>
	static Intersection* getRayLineIntersection(sf::Vector2f first_point, sf::Vector2f second_point, Ray* ray);
private:
	std::vector<Ray*> rays;
};