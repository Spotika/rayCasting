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
	sf::Vector2<int> position;
	/// <summary>
	/// ���� �������� ������������ ������� � ��������
	/// </summary>
	double orientation;

	/// <summary>
	/// ���������� ��������� ��������
	/// </summary>
	virtual void update() { throw; };
};