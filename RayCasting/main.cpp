#include<iostream>
#include "Main.h"
#include "Screen.h"
#include "AppManager.h"
#include "MainApp.h"
#include "MonoFactory.h"
#include "EventHandler.h"
#include <iomanip>
#include "TestApp.h"

void Main::linkApps() {
	AppManager* app_manager = AppManager::getInstance();

	// link apps
	app_manager->addCreateFunction("MainApp", MonoFactory<AbstractApp, MainApp>().getCreateFunction());
	app_manager->addCreateFunction("TestApp", MonoFactory<AbstractApp, TestApp>().getCreateFunction());
}

void Main::start() {
	std::cout << std::fixed << std::setprecision(4);

	Screen::getInstance()->init();
	EventHandler::getInstance()->init();

	linkApps();

	AppManager::getInstance()->addAppToQueue("MainApp");
	// ����� ��������� �����
	AppManager::getInstance()->startLoop();

	// ����� ������
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
