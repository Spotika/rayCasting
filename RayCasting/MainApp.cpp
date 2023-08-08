#include "MainApp.h"
#include "EventHandler.h"
#include "Screen.h"
#include "MainLevel.h"
#include "MiniMap.h"
#include "LevelRenderer.h"
#include "Player.h"
#include "PlayerKeyboardController.h"
#include "Config.h"
#include<iostream>

void MainApp::start() {
	std::cout << "Starting mainApp\n";
	loop();
}

void MainApp::loop() {
	EventHandler* event_handler = EventHandler::getInstance();
	Screen* screen = Screen::getInstance();

	AbstractLevel* level = new MainLevel();
	Player* player = new Player({0, 0}, 0);
	

	// ����������� ������ � ������
	level->addEntity(player);

	// ����������� ����������� � ������
	PlayerKeyboardController* player_controller = new PlayerKeyboardController(player);

	// ����������� ����������� � ������
	level->addController(player_controller);

	// �������� ������� � ���������
	LevelRenderer* renderer = new LevelRenderer(level, player);
	MiniMap* mini_map = new MiniMap(level, {0, 0}, 300, 300);

	while (true) {
		// ���������� ������
		level->update();

		// ��������� ������
		renderer->render();
		// ��������� ���������
		mini_map->show();

		// ���������� ������� � �������
		event_handler->update();

		screen->getRenderWindow()->display();
		screen->getRenderWindow()->clear(config::color::black);
	}
	stop();
}

void MainApp::stop() {

}