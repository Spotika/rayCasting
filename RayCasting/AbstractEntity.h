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
	sf::Vector2f position;
	/// <summary>
	/// угол поворота относительно востока в радианах
	/// </summary>
	float orientation;

	AbstractEntity() : orientation{ 0.0 }, position{ 0, 0 } {};
	AbstractEntity(sf::Vector2f position, float orientation) : position{ position }, orientation{ orientation } {};

	/// <summary>
	/// Обновление состояния существа
	/// </summary>
	virtual void update() { throw; };
};