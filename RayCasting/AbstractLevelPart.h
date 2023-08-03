#pragma once
#include "MiniMap.h"
#include "RayCaster.h"


class AbstractLevelPart {
	/// <summary>
	/// ������ ���� �� ���������
	/// </summary>
	/// <param name="mini_map">������ ���������</param>
	virtual void drawOnMiniMap(MiniMap* mini_map) { throw; };
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="ray">��������� �� ������ ����</param>
	/// <returns>���������� ������ Intersection ��� ���� � ����</returns>
	virtual RayCaster::Intersection getIntersection(RayCaster::Ray* ray) { throw; };
};