#pragma once
#include "IControlled.h"


class IFloatParameterControlled : public IControlled {
public:
	/// <summary>
	/// Устанавливает параметр value
	/// </summary>
	/// <param name="value"></param>
	virtual void setParameter(float value) { throw; };
	/// <summary>
	/// Меняет параметер на diff
	/// </summary>
	/// <param name="diff"></param>
	virtual void changeParameter(float diff) { throw; };
};