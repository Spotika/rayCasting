#pragma once
#include "AbstractLevel.h"


class LevelRenderer {
private:
	/// <summary>
	/// ��������� �� ������ ������
	/// </summary>
	AbstractLevel* level;

public:


	LevelRenderer(AbstractLevel* level);

	/// <summary>
	/// ���������� �� ������ ����������� ������
	/// </summary>
	void render();
};