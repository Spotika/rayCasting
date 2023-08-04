#pragma once
#include "AbstractLevel.h"
#include "Player.h"

/// <summary>
/// ���������� ������� �� ������ ������������ ������
/// </summary>
class LevelRenderer {
private:
	/// <summary>
	/// ��������� �� ������ ������
	/// </summary>
	AbstractLevel* level;

	/// <summary>
	/// ��������� �� ������ �� ���� �������� ���� ���������
	/// </summary>
	Player* player;
public:

	LevelRenderer(AbstractLevel* level, Player* player);

	/// <summary>
	/// ���������� �� ������ ����������� ������
	/// </summary>
	void render();
};