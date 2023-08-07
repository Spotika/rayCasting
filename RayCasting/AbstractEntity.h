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
	sf::Vector2f position;
	/// <summary>
	/// ���� �������� ������������ ������� � ��������
	/// </summary>
	float orientation;

	AbstractEntity() : orientation{ 0.0 }, position{ 0, 0 } {};
	AbstractEntity(sf::Vector2f position, float orientation) : position{ position }, orientation{ orientation } {};

	/// <summary>
	/// ���������� ��������� ��������
	/// </summary>
	virtual void update() { throw; };
};