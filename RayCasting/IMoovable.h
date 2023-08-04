#pragma once
#include "IControlled.h"
#include "SFML/Graphics.hpp"

/// <summary>
/// Интерфейс движимого существа
/// </summary>
class IMoovable : public IControlled {
public:

	virtual double getMovingSpeed() { throw; };

	virtual double getRotatingSpeed() { throw; };

	/// <summary>
	/// Перемещение в точку target_pos
	/// </summary>
	/// <param name="target_pos">Целевая точка</param>
	virtual void moveTo(sf::Vector2<double> target_pos) { throw; };

	/// <summary>
	/// 
	/// </summary>
	/// <returns>Возвращает позицию</returns>
	virtual sf::Vector2<double> getPosition() { throw; };


	/// <summary>
	/// 
	/// </summary>
	/// <returns>Возвращает угол поворота</returns>
	virtual double getOrientation() { throw; };

	/// <summary>
	/// перемещение на diff_pos
	/// </summary>
	/// <param name="diff_pos"></param>
	virtual void move(sf::Vector2<double> diff_pos) { throw; };

	/// <summary>
	/// Поворачивает на orientation_diff
	/// </summary>
	/// <param name="orientation_diff">Угол поворота в радианах</param>
	virtual void rotate(double orientation_diff) { throw; }

	/// <summary>
	/// Устанавливает поворот orientation
	/// </summary>
	/// <param name="orientation">Угол поворота в радианах</param
	virtual void rotateTo(double orientation) { throw; }
};