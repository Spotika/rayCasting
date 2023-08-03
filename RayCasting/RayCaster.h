#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "AbstractLevelPart.h"

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
		sf::Vector2<int> start_point;
		/// <summary>
		/// ���� �������� � �������� ������������ �������
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
		/// <returns>���������� ��������� ����� ������ ����������� � ������� ����</returns>
		double getDistance() const;
	};

	/// <summary>
	/// ������� ����� �����
	/// </summary>
	/// <param name="start_point">����� ���������� �����</param>
	/// <param name="num_of_rays">���������� �����</param>
	/// <param name="orientation">����������� ����������� ����: ���� � �������� ������������ �������</param>
	/// <param name="fov">���� ��������������� ����� ������������ orientation</param>
	void cast(sf::Vector2<int> start_point, int num_of_rays, double orientation, double fov);

	/// <summary>
	/// �������� ����������� � ���������
	/// </summary>
	/// <param name="level_parts">������ �� ������ �������� ������</param>
	/// <returns>���������� ������ �����������</returns>
	std::vector<Intersection>& getInstersections(std::vector<AbstractLevelPart*>& level_parts);
private:
	std::vector<Ray*> rays;
};