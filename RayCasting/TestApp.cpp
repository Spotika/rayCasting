#include "TestApp.h"
#include "EventHandler.h"
#include "Screen.h"
#include "RayCaster.h"
#include<iostream>
#include<numbers>

void TestApp::start() {
	std::cout << "Start Testing \n";
	loop();
}

void TestApp::loop() {
	EventHandler* event_handler = EventHandler::getInstance();
	Screen* screen = Screen::getInstance();

	RayCaster rc;

	RayCaster::Intersection* inter = rc.getRayLineIntersection({ 8, 2 }, { 2, 8 }, new RayCaster::Ray{ {0, 0}, std::numbers::pi / 4 });


	if (inter == nullptr) {
		std::cout << "LOX\n";
	}
	else {
		std::cout << inter->position.x << " " << inter->position.y << "\n";
	}

	delete inter;

	//while (true) {



	//}
	stop();
}




void TestApp::stop() {

}