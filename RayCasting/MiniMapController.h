#pragma once
#include "IFloatParameterControlled.h"
#include "AbstractController.h"

class MiniMapController : public AbstractController {
public:
	MiniMapController(IFloatParameterControlled* target) : AbstractController(target) {}

	void update();
};