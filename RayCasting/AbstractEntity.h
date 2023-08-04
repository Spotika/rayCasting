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
	sf::Vector2<double> position;
	/// <summary>
	/// угол поворота относительно востока в радианах
	/// </summary>
	double orientation;

	AbstractEntity() : orientation{ 0.0 }, position{ 0, 0 } {};
	AbstractEntity(sf::Vector2<double> position, double orientation) : position{ position }, orientation{ orientation } {};

	/// <summary>
	/// Обновление состояния существа
	/// </summary>
	virtual void update() { throw; };
};