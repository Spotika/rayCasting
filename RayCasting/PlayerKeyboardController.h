#pragma once
#include "AbstractController.h"
#include "IMoovable.h"

class PlayerKeyboardController : public AbstractController {
public:
	PlayerKeyboardController(IMoovable* target) : AbstractController(target) {};
	void update();
};