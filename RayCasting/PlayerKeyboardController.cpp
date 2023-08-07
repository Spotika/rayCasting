#include "PlayerKeyboardController.h"
#include "EventHandler.h"
#include "Screen.h"
#include <numbers>
#include "iostream"
#include "Config.h"
#include <cmath>

using namespace config::control_buttons_codes;


void PlayerKeyboardController::update() {
	EventHandler* event_handler = EventHandler::getInstance();

	float dt = event_handler->getTimeElapsed();
	IMoovable* player = (IMoovable*)target;


	// логика перемещения
	sf::Vector2f total_moving{0, 0};
	float teta = player->getOrientation();
	float total_rotation = 0;
	float pi = std::numbers::pi;
	float mod = dt * player->getMovingSpeed();

	if (sf::Keyboard::isKeyPressed(player_foward)) {
		total_moving.x += mod * std::cos(teta);
		total_moving.y += mod * std::sin(teta);
	}
	else if (sf::Keyboard::isKeyPressed(player_backward)) {
		total_moving.x -= mod * std::cos(teta);
		total_moving.y -= mod * std::sin(teta);
	}
	if (sf::Keyboard::isKeyPressed(player_left)) {
		total_moving.x -= mod * std::cos(teta - pi / 2);
		total_moving.y -= mod * std::sin(teta - pi / 2);
	} else if (sf::Keyboard::isKeyPressed(player_right)) {
		total_moving.x -= mod * std::cos(teta + pi / 2);
		total_moving.y -= mod * std::sin(teta + pi / 2);
	}



	auto* window = Screen::getInstance()->getRenderWindow();

	sf::Vector2 center{config::window::width / 2 + window->getPosition().x, config::window::height / 2 + window->getPosition().y};

	if (event_handler->global->mouse_fixed) {
		if (window->hasFocus()) {
			total_rotation = config::player::rotate_sense * (center.x - sf::Mouse::getPosition().x);
			sf::Mouse::setPosition(center);
		}
	}
	player->move(total_moving);
	player->rotate(total_rotation);
}