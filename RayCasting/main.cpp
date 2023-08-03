#include<iostream>
#include "Main.h"
#include "Screen.h"
#include "AppManager.h"
#include "MainApp.h"
#include "MonoFactory.h"
#include "EventHandler.h"
#include "TestApp.h"

void Main::linkApps() {
	AppManager* app_manager = AppManager::getInstance();

	// link apps
	app_manager->addCreateFunction("MainApp", MonoFactory<AbstractApp, MainApp>().getCreateFunction());
	app_manager->addCreateFunction("TestApp", MonoFactory<AbstractApp, TestApp>().getCreateFunction());
}

void Main::start() {
	Screen::getInstance()->init();
	EventHandler::getInstance()->init();
	linkApps();

	AppManager::getInstance()->addAppToQueue("TestApp");
	// старт основного цикла
	AppManager::getInstance()->startLoop();

	// конец работы
	stop();
}

void Main::stop() {
	std::cout << "Programm ended";
	exit(0);
}

int main() {
	Main::start();

	return 0;
}