#pragma once
#include "MiniMap.h"


/// <summary>
/// ��������� ��� ��������, ������� ����� ���� ���������� �� ���������
/// </summary>
class IDrawableOnMinimap {
public:
	/// <summary>
	/// ������ ���� �� ���������
	/// </summary>
	/// <param name="mini_map">��������� �� ���������</param>
	virtual void drawOnMiniMap(MiniMap* mini_map) { throw; };
};