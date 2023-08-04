#pragma once
#include "IControlled.h"


class AbstractController {
protected:
	IControlled* target;
public:
	AbstractController(IControlled* target) : target{ target } {};

	/// <summary>
	/// ���������� �����������
	/// </summary>
	virtual void update() { throw; };
};