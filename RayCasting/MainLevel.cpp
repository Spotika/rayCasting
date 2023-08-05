#include "MainLevel.h"
#include "Wall.h"
#include "SFML/Graphics.hpp"
#include "WallPolygon.h"
#include <iostream>

void MainLevel::update() {
	AbstractLevel::update();
}

MainLevel::MainLevel() {
	// инициализация уровня
	level_parts = {
		new part::WallPolygon({{10, 10}, {10, 100}, {100, 100}, {100, 10}}),
		new part::Wall({10, 10}, {100, 100}),
	};

	width = 200;
	height = 200;
}

int MainLevel::getHeight() {
	return height;
}

int MainLevel::getWidth() {
	return width;
}
