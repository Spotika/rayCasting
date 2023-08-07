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
			{50, 50},
			{50, 100},
			{100, 100},
			{100, 50},
			{200, 200},
			}),
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
