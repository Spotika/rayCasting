#pragma once
#include "AbstractLevel.h"
#include "Player.h"
#include "RayCaster.h"

/// <summary>
/// ���������� ������� �� ������ ������������ ������
/// </summary>
class LevelRenderer {
private:
	/// <summary>
	/// ��������� �� ������ ������
	/// </summary>
	AbstractLevel* level;

	RayCaster* ray_caster;

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

	~LevelRenderer() {
		delete ray_caster;
	}
};