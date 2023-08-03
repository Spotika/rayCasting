#pragma once
#include "MiniMap.h"
#include "RayCaster.h"


class AbstractLevelPart {
	/// <summary>
	/// Рисует себя на миникарте
	/// </summary>
	/// <param name="mini_map">Объект миникарты</param>
	virtual void drawOnMiniMap(MiniMap* mini_map) { throw; };
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="ray">указатель на объект луча</param>
	/// <returns>Возвращает объект Intersection для себя и луча</returns>
	virtual RayCaster::Intersection getIntersection(RayCaster::Ray* ray) { throw; };
};