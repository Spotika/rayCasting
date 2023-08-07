#pragma once
#include "MiniMap.h"
#include "RayCaster.h"


class AbstractLevelPart {
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="ray">��������� �� ������ ����</param>
	/// <returns>���������� ������ Intersection ��� ���� � ����</returns>
	virtual RayCaster::Intersection* getIntersection(RayCaster::Ray* ray) { throw; };
};