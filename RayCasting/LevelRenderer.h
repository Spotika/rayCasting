#pragma once
#include "AbstractLevel.h"


class LevelRenderer {
private:
	/// <summary>
	/// Указатель на объект уровня
	/// </summary>
	AbstractLevel* level;

public:


	LevelRenderer(AbstractLevel* level);

	/// <summary>
	/// отображает на экране изображение уровня
	/// </summary>
	void render();
};