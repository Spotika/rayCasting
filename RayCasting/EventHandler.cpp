#include "EventHandler.h"
#include "Screen.h"
#include "Main.h"


void EventHandler::handleGlobalEvent(sf::Event event) {
	// выход из программы
	if (event.type == sf::Event::Closed) {
		Main::stop();
	}
}

void EventHandler::init() {
	event_list = new std::vector<sf::Event>();
}

void EventHandler::update() {
	sf::Event event;
	sf::Window* window = Screen::getInstance()->getRenderWindow();
	event_list->clear();

	while (window->pollEvent(event)) {
		handleGlobalEvent(event);
		event_list->push_back(event);
	}
}

std::vector<sf::Event>* EventHandler::getEvents() {
	return event_list;
}