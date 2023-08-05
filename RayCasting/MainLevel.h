#pragma once
#include "AbstractLevel.h"

class MainLevel : public AbstractLevel {
public:
	int width;
	int height;

	MainLevel();

	int getWidth();

	int getHeight();

	void update();
};