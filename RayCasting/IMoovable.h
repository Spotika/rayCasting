#pragma once
#include "IControlled.h"
#include "SFML/Graphics.hpp"

/// <summary>
/// ��������� ��������� ��������
/// </summary>
class IMoovable : public IControlled {
public:

	virtual double getMovingSpeed() { throw; };

	virtual double getRotatingSpeed() { throw; };

	/// <summary>
	/// ����������� � ����� target_pos
	/// </summary>
	/// <param name="target_pos">������� �����</param>
	virtual void moveTo(sf::Vector2<double> target_pos) { throw; };

	/// <summary>
	/// 
	/// </summary>
	/// <returns>���������� �������</returns>
	virtual sf::Vector2<double> getPosition() { throw; };


	/// <summary>
	/// 
	/// </summary>
	/// <returns>���������� ���� ��������</returns>
	virtual double getOrientation() { throw; };

	/// <summary>
	/// ����������� �� diff_pos
	/// </summary>
	/// <param name="diff_pos"></param>
	virtual void move(sf::Vector2<double> diff_pos) { throw; };

	/// <summary>
	/// ������������ �� orientation_diff
	/// </summary>
	/// <param name="orientation_diff">���� �������� � ��������</param>
	virtual void rotate(double orientation_diff) { throw; }

	/// <summary>
	/// ������������� ������� orientation
	/// </summary>
	/// <param name="orientation">���� �������� � ��������</param
	virtual void rotateTo(double orientation) { throw; }
};