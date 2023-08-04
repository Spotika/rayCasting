#include "MainApp.h"
#include "EventHandler.h"
#include "Screen.h"
#include "MainLevel.h"
#include "MiniMap.h"
#include "LevelRenderer.h"
#include "Player.h"
#include<iostream>

void MainApp::start() {
	std::cout << "Starting mainApp\n";
	loop();
}

void MainApp::loop() {
	EventHandler* event_handler = EventHandler::getInstance();
	Screen* screen = Screen::getInstance();

	AbstractLevel* level = new MainLevel();
	Player* player = new Player();


	LevelRenderer* renderer = new LevelRenderer(level, player);
	MiniMap* mini_map = new MiniMap(level);

	while (true) {
		level->update();
		renderer->render();
		mini_map->show();

		event_handler->update();
		screen->getRenderWindow()->display();
	}
	stop();
}

void MainApp::stop() {

}