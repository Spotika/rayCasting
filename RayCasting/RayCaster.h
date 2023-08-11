#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class AbstractLevelPart;

class RayCaster {
public:
	/// <summary>
	/// ����� ����
	/// </summary>
	class Ray {
	public:
		/// <summary>
		/// ����� ���������� ����
		/// </summary>
		sf::Vector2f start_point;
		/// <summary>
		/// ���� �������� � �������� ������������ �������
		/// </summary>
		float orientation;
		/// <summary>
		/// ����� ���� ��� ���������
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
		/// ����� �� ������ �� ������� ����� ����� ����������� ������
		/// </summary>
		float part_of_object;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>���������� ��������� ����� ������ ����������� � ������� ����</returns>
		float getDistance() const;

		Intersection(Ray ray, const sf::Vector2f& position) : ray(ray), position(position), part_of_object(0) {};

		~Intersection() {}
	};

	/// <summary>
	/// ������� ����� �����
	/// </summary>
	/// <param name="start_point">����� ���������� �����</param>
	/// <param name="num_of_rays">���������� �����</param>
	/// <param name="orientation">����������� ����������� ����: ���� � �������� ������������ �������</param>
	/// <param name="fov">���� ��������������� ����� ������������ orientation</param>
	void cast(sf::Vector2f start_point, int num_of_rays, float orientation, float fov);

	/// <summary>
	/// �������� ����������� � ���������
	/// </summary>
	/// <param name="level_parts">������ �� ������ �������� ������</param>
	/// <returns>���������� ������ �����������</returns>
	std::vector<Intersection*> getInstersections(std::vector<AbstractLevelPart*>& level_parts);

	/// <summary>
	/// ���������� ����������� ���� � ��������
	/// ����� ������� ����������� ����� �������������
	/// </summary>
	/// <param name="first_point"></param>
	/// <param name="second_point"></param>
	/// <param name="ray"></param>
	/// <returns></returns>
	static Intersection* getRayLineIntersection(sf::Vector2f first_point, sf::Vector2f second_point, Ray* ray);
private:
	std::vector<Ray*> rays;
};