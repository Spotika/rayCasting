#pragma once
#include "SFML/Graphics.hpp"

/// <summary>
/// класс сущности
/// </summary>
class AbstractEntity {
public:
	/// <summary>
	/// позиция
	/// </summary>
	sf::Vector2<int> position;
	/// <summary>
	/// угол поворота относительно востока в радианах
	/// </summary>
	double orientation;

	/// <summary>
	/// Обновление состояния существа
	/// </summary>
	virtual void update() { throw; };
};