#pragma once
#include "SFML/Graphics.hpp"


/// <summary>
/// ����� ��������
/// </summary>
class AbstractEntity {
public:
	/// <summary>
	/// �������
	/// </summary>
	sf::Vector2<double> position;
	/// <summary>
	/// ���� �������� ������������ ������� � ��������
	/// </summary>
	double orientation;

	AbstractEntity() : orientation{ 0.0 }, position{ 0, 0 } {};
	AbstractEntity(sf::Vector2<double> position, double orientation) : position{ position }, orientation{ orientation } {};

	/// <summary>
	/// ���������� ��������� ��������
	/// </summary>
	virtual void update() { throw; };
};