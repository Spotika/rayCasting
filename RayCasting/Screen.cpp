#include "Screen.h"
#include "Config.h"

void Screen::init() {
	render_window = new sf::RenderWindow(sf::VideoMode(config::window::width, config::window::height), config::window::title);
	render_window->setFramerateLimit(config::window::FPS);
}

sf::RenderWindow* Screen::getRenderWindow() {
	return render_window;
}