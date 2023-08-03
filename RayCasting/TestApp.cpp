#include "TestApp.h"
#include "EventHandler.h"
#include "Screen.h"
#include<iostream>

void TestApp::start() {
	std::cout << "Start Testing \n";
	loop();
}

void TestApp::loop() {
	EventHandler* event_handler = EventHandler::getInstance();
	Screen* screen = Screen::getInstance();
	while (true) {

		event_handler->update();
		screen->getRenderWindow()->display();
	}
	stop();
}




void TestApp::stop() {

}