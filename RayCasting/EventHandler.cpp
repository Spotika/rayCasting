#include "EventHandler.h"
#include "Screen.h"
#include "Main.h"


void EventHandler::handleGlobalEvent(sf::Event event) {
	// ����� �� ���������
	if (event.type == sf::Event::Closed) {
		Main::stop();
	}
}

void EventHandler::init() {
	event_list = new std::vector<sf::Event>();
	clock = new sf::Clock();
}

void EventHandler::update() {
	sf::Event event;
	sf::Window* window = Screen::getInstance()->getRenderWindow();
	event_list->clear();
	// ���������� ������� � ������
	while (window->pollEvent(event)) {
		handleGlobalEvent(event);
		event_list->push_back(event);
	}

	// ���������� clock
	time_elapsed = clock->restart().asSeconds();
}

std::vector<sf::Event>* EventHandler::getEvents() {
	return event_list;
}

sf::Clock* EventHandler::getClock() {
	return clock;
}

double EventHandler::getTimeElapsed() {
	return time_elapsed;
}