#pragma once
#include "AbstractLevel.h"
#include "Player.h"

/// <summary>
/// отображает уровень на экране относительно игрока
/// </summary>
class LevelRenderer {
private:
	/// <summary>
	/// ”казатель на объект уровн€
	/// </summary>
	AbstractLevel* level;

	/// <summary>
	/// ”казатель на игрока от лица которого идет отрисовка
	/// </summary>
	Player* player;
public:

	LevelRenderer(AbstractLevel* level, Player* player);

	/// <summary>
	/// отображает на экране изображение уровн€
	/// </summary>
	void render();
};