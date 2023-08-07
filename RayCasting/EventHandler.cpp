#include "EventHandler.h"
#include "Screen.h"
#include "Config.h"
#include "Main.h"


void EventHandler::handleGlobalEvent(sf::Event event) {
	// выход из программы
	if (event.type == sf::Event::Closed) {
		Main::stop();
	}
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == config::control_buttons_codes::exit_button) {
			Main::stop();
		}
		if (event.key.code == config::control_buttons_codes::fix_mouse) {
			global->mouse_fixed = !global->mouse_fixed;
			Screen::getInstance()->getRenderWindow()->setMouseCursorVisible(!global->mouse_fixed);
		}
	}

}

void EventHandler::init() {
	event_list = new std::vector<sf::Event>();
	clock = new sf::Clock();
	global = new Global();
	Screen::getInstance()->getRenderWindow()->setMouseCursorVisible(false);
}

void EventHandler::update() {
	sf::Event event;
	sf::Window* window = Screen::getInstance()->getRenderWindow();
	event_list->clear();
	// добавление событий в список
	while (window->pollEvent(event)) {
		handleGlobalEvent(event);
		event_list->push_back(event);
	}

	// обновление clock
	time_elapsed = clock->restart().asSeconds();
}

std::vector<sf::Event>* EventHandler::getEvents() {
	return event_list;
}

sf::Clock* EventHandler::getClock() {
	return clock;
}

float EventHandler::getTimeElapsed() {
	return time_elapsed;
}