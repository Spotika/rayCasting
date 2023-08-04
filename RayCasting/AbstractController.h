#pragma once
#include "IControlled.h"

class AbstractController {
private:
	IControlled* target;
public:
	AbstractController(IControlled* target);

	/// <summary>
	/// обновление контроллера
	/// </summary>
	virtual void update();
};