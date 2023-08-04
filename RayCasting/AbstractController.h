#pragma once
#include "IControlled.h"

class AbstractController {
private:
	IControlled* target;
public:
	AbstractController(IControlled* target);

	/// <summary>
	/// ���������� �����������
	/// </summary>
	virtual void update();
};