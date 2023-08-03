#include "Screen.h"
#include "Config.h"

void Screen::init() {
	render_window = new sf::RenderWindow(sf::VideoMode(config::window::width, config::window::height), config::window::title);
}

sf::RenderWindow* Screen::getRenderWindow() {
	return render_window;
}