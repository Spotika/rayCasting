#pragma once
#include "IControlled.h"


class AbstractController {
protected:
	IControlled* target;
public:
	AbstractController(IControlled* target) : target{ target } {};

	/// <summary>
	/// обновление контроллера
	/// </summary>
	virtual void update() { throw; };
};