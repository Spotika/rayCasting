#include "PlayerKeyboardController.h"
#include "EventHandler.h"
#include "iostream"
#include "Config.h"
#include <cmath>

using namespace config::control_buttons_codes;


void PlayerKeyboardController::update() {
	EventHandler* event_handler = EventHandler::getInstance();

	float dt = event_handler->getTimeElapsed();
	IMoovable* player = (IMoovable*) target;


	// логика перемещения
	sf::Vector2f total_moving{0, 0};
	float teta = player->getOrientation();
	float total_rotation = 0;

	float mod = dt * player->getMovingSpeed();

	if (sf::Keyboard::isKeyPressed(player_foward)) {
		total_moving.x += mod * std::cos(teta);
		total_moving.y += mod * std::sin(teta);
	}
	else if (sf::Keyboard::isKeyPressed(player_backward)) {
		total_moving.x -= mod * std::cos(teta);
		total_moving.y -= mod * std::sin(teta);
	}

	if (sf::Keyboard::isKeyPressed(player_rotate_left)) {
		total_rotation += dt * player->getRotatingSpeed();
	}
	else if (sf::Keyboard::isKeyPressed(player_rotate_right)) {
		total_rotation -= dt * player->getRotatingSpeed();
	}


	player->move(total_moving);
	player->rotate(total_rotation);

	//std::cout << player->getposition().x << " " << player->getposition().y
	//	<< " | " << player->getorientation() <<  "\n";

}