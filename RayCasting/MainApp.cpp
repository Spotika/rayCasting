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
	

	// подключение игрока к уровню
	level->addEntity(player);

	// подключение контроллера к игроку
	PlayerKeyboardController* player_controller = new PlayerKeyboardController(player);

	// подключение контроллера к уровню
	level->addController(player_controller);

	// создание рендера и миникарты
	LevelRenderer* renderer = new LevelRenderer(level, player);
	MiniMap* mini_map = new MiniMap(level, {0, 0}, 300, 300);

	while (true) {
		// обновление уровня
		level->update();

		// отрисовка уровня
		renderer->render();
		// отрисовка миникарты
		mini_map->show();

		// обновление дисплея и событий
		event_handler->update();

		screen->getRenderWindow()->display();
		screen->getRenderWindow()->clear(config::color::black);
	}
	stop();
}

void MainApp::stop() {

}