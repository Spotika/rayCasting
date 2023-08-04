#pragma once
#include "IControlled.h"
#include "SFML/Graphics.hpp"

/// <summary>
/// ��������� ��������� ��������
/// </summary>
class IMoovable : public IControlled {
protected:
	int speed;
public:
	virtual void moveTo(sf::Vector2<int> target_pos);
};