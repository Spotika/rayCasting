#pragma once
#include "IControlled.h"
#include "SFML/Graphics.hpp"

/// <summary>
/// Интерфейс движимого существа
/// </summary>
class IMoovable : public IControlled {
protected:
	int speed;
public:
	virtual void moveTo(sf::Vector2<int> target_pos);
};