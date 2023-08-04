#pragma once
#include "AbstractLevel.h"

class MainLevel : public AbstractLevel {
public:
	int width = 500;
	int height = 500;

	MainLevel();

	int getWidth();

	int getHeight();

	void update();
};