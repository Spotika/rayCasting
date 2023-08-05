#pragma once
#include "IControlled.h"
#include "SFML/Graphics.hpp"

/// <summary>
/// ��������� ��������� ��������
/// </summary>
class IMoovable : public IControlled {
public:

	virtual float getMovingSpeed() { throw; };

	virtual float getRotatingSpeed() { throw; };

	/// <summary>
	/// ����������� � ����� target_pos
	/// </summary>
	/// <param name="target_pos">������� �����</param>
	virtual void moveTo(sf::Vector2f target_pos) { throw; };

	/// <summary>
	/// 
	/// </summary>
	/// <returns>���������� �������</returns>
	virtual sf::Vector2f getPosition() { throw; };


	/// <summary>
	/// 
	/// </summary>
	/// <returns>���������� ���� ��������</returns>
	virtual float getOrientation() { throw; };

	/// <summary>
	/// ����������� �� diff_pos
	/// </summary>
	/// <param name="diff_pos"></param>
	virtual void move(sf::Vector2f diff_pos) { throw; };

	/// <summary>
	/// ������������ �� orientation_diff
	/// </summary>
	/// <param name="orientation_diff">���� �������� � ��������</param>
	virtual void rotate(float orientation_diff) { throw; }

	/// <summary>
	/// ������������� ������� orientation
	/// </summary>
	/// <param name="orientation">���� �������� � ��������</param
	virtual void rotateTo(float orientation) { throw; }
};