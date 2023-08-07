#pragma once
#include "MiniMap.h"
#include "RayCaster.h"


class AbstractLevelPart {
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="ray">указатель на объект луча</param>
	/// <returns>Возвращает объект Intersection для себя и луча</returns>
	virtual RayCaster::Intersection* getIntersection(RayCaster::Ray* ray) { throw; };
};