#include "MainLevel.h"
#include "Wall.h"
#include "SFML/Graphics.hpp"
#include <iostream>

void MainLevel::update() {
	AbstractLevel::update();
}

MainLevel::MainLevel() {

}

int MainLevel::getHeight() {
	return height;
}

int MainLevel::getWidth() {
	return width;
}
