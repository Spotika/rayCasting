#include "MainLevel.h"
#include "Wall.h"
#include "SFML/Graphics.hpp"
#include "WallPolygon.h"
#include <iostream>

void MainLevel::update() {
	AbstractLevel::update();
}

MainLevel::MainLevel() {
	// ������������� ������
	level_parts = {
		new part::WallPolygon({
			{50, 50}, // 1 �����
			{50, 100}, // 2 �����
			{100, 100}, // 3 ����� � ��
			{100, 50}, 
			{200, 200},
			}),
		new part::Wall({100, 100}/*���������� 1 �����*/, {100, 200}/*���������� 2 �����*/),
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
