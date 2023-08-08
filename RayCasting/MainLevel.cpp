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
		new part::Wall({0, 0}, {80, 0}),
		new part::Wall({120, 0}, {400, 0}),
		new part::Wall({120, 40}, {160, 40}),
		new part::Wall({320, 40}, {360, 40}),
		new part::Wall({40, 80}, {200, 80}),
		new part::Wall({240, 80}, {360, 80}),
		new part::Wall({0, 120}, {40, 120}),
		new part::Wall({100, 120}, {160, 120}),
		new part::Wall({200, 120}, {240, 120}),
		new part::Wall({280, 120}, {320, 120}),
		new part::Wall({360, 120}, {400, 120}),
		new part::Wall({60, 160}, {80, 160}),
		new part::Wall({160, 160}, {280, 160}),
		new part::Wall({320, 160}, {360, 160}),
		new part::Wall({0, 200}, {160, 200}),
		new part::Wall({240, 200}, {320, 200}),
		new part::Wall({80, 240}, {200, 240}),
		new part::Wall({360, 240}, {400, 240}),
		new part::Wall({120, 280}, {160, 280}),
		new part::Wall({200, 280}, {240, 280}),
		new part::Wall({320, 280}, {360, 280}),
		new part::Wall({0, 320}, {160, 320}),
		new part::Wall({240, 320}, {320, 320}),
		new part::Wall({40, 360}, {240, 360}),
		new part::Wall({320, 360}, {360, 360}),
		new part::Wall({0, 400}, {400, 400}),
		new part::Wall({0, 0}, {0, 160}),
		new part::Wall({0, 200}, {0, 400}),
		new part::Wall({40, 0}, {40, 40}),
		new part::Wall({40, 200}, {40, 220}),
		new part::Wall({40, 260}, {40, 280}),
		new part::Wall({80, 40}, {80, 100}),
		new part::Wall({80, 140}, {80, 160}),
		new part::Wall({80, 240}, {80, 280}),
		new part::Wall({120, 160}, {120, 200}),
		new part::Wall({120, 240}, {120, 280}),
		new part::Wall({160, 0}, {160, 40}),
		new part::Wall({160, 120}, {160, 160}),
		new part::Wall({160, 280}, {160, 320}),
		new part::Wall({200, 40}, {200, 120}),
		new part::Wall({200, 160}, {200, 200}),
		new part::Wall({200, 240}, {200, 360}),
		new part::Wall({240, 40}, {240, 80}),
		new part::Wall({240, 200}, {240, 280}),
		new part::Wall({280, 0}, {280, 40}),
		new part::Wall({280, 240}, {280, 400}),
		new part::Wall({320, 40}, {320, 80}),
		new part::Wall({320, 120}, {320, 280}),
		new part::Wall({360, 80}, {360, 120}),
		new part::Wall({360, 200}, {360, 240}),
		new part::Wall({360, 280}, {360, 360}),
		new part::Wall({400, 0}, {400, 200}),
		new part::Wall({400, 240}, {400, 400}),
	};

	width = 1000;
	height = 1000;
}

int MainLevel::getHeight() {
	return height;
}

int MainLevel::getWidth() {
	return width;
}
