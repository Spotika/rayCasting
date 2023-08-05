#pragma once
#include "IControlled.h"
#include "SFML/Graphics.hpp"

/// <summary>
/// Интерфейс движимого существа
/// </summary>
class IMoovable : public IControlled {
public:

	virtual float getMovingSpeed() { throw; };

	virtual float getRotatingSpeed() { throw; };

	/// <summary>
	/// Перемещение в точку target_pos
	/// </summary>
	/// <param name="target_pos">Целевая точка</param>
	virtual void moveTo(sf::Vector2f target_pos) { throw; };

	/// <summary>
	/// 
	/// </summary>
	/// <returns>Возвращает позицию</returns>
	virtual sf::Vector2f getPosition() { throw; };


	/// <summary>
	/// 
	/// </summary>
	/// <returns>Возвращает угол поворота</returns>
	virtual float getOrientation() { throw; };

	/// <summary>
	/// перемещение на diff_pos
	/// </summary>
	/// <param name="diff_pos"></param>
	virtual void move(sf::Vector2f diff_pos) { throw; };

	/// <summary>
	/// Поворачивает на orientation_diff
	/// </summary>
	/// <param name="orientation_diff">Угол поворота в радианах</param>
	virtual void rotate(float orientation_diff) { throw; }

	/// <summary>
	/// Устанавливает поворот orientation
	/// </summary>
	/// <param name="orientation">Угол поворота в радианах</param
	virtual void rotateTo(float orientation) { throw; }
};