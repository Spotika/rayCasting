#pragma once
#include "MiniMap.h"


/// <summary>
/// Интерфейс для объектов, которые могут быть отображены на миникарте
/// </summary>
class IDrawableOnMinimap {
public:
	/// <summary>
	/// Рисует себя на миникарте
	/// </summary>
	/// <param name="mini_map">указатель на миникарту</param>
	virtual void drawOnMiniMap(MiniMap* mini_map) { throw; };
};