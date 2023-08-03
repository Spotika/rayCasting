#pragma once
#include "AbstractApp.h"


class MainApp : public AbstractApp {
public:
	void start();
	void loop();
	void stop();
};