#pragma once
#include "IControlled.h"


class IFloatParameterControlled : public IControlled {
public:
	/// <summary>
	/// ������������� �������� value
	/// </summary>
	/// <param name="value"></param>
	virtual void setParameter(float value) { throw; };
	/// <summary>
	/// ������ ��������� �� diff
	/// </summary>
	/// <param name="diff"></param>
	virtual void changeParameter(float diff) { throw; };
};