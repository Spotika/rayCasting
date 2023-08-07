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
		new part::WallPolygon({
			{50, 50}, // 1 точка
			{50, 100}, // 2 точка
			{100, 100}, // 3 точка и тд
			{100, 50}, 
			{200, 200},
			}),
		new part::Wall({100, 100}/*координата 1 точки*/, {100, 200}/*координата 2 точки*/),
	};

	width = 500;
	height = 500;
}

int MainLevel::getHeight() {
	return height;
}

int MainLevel::getWidth() {
	return width;
}
