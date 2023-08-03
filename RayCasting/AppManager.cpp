#include "AppManager.h"

void AppManager::startLoop() {
	while (!app_queue.empty()) {
		AbstractApp* cur_app = app_queue.front();
		app_queue.pop();
		cur_app->start();
	}
}

void AppManager::startApp(std::string name) {
	checkName(name);
	AbstractApp* new_app = create_function_by_name[name]();
	new_app->start();
}

void AppManager::addAppToQueue(std::string name) {
	checkName(name);
	AbstractApp* new_app = create_function_by_name[name]();
	app_queue.push(new_app);
}

void AppManager::addCreateFunction(std::string name, AbstractApp* (*function)()) {
	create_function_by_name[name] = function;
}