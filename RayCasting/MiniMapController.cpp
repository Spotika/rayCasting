#include "MiniMapController.h"
#include "Config.h"
#include "SFML/Graphics.hpp"
#include "EventHandler.h"

using namespace config::control_buttons_codes;

void MiniMapController::update() {

	IFloatParameterControlled* mini_map = (IFloatParameterControlled*)target;
	float dt = EventHandler::getInstance()->getTimeElapsed();

	if (sf::Keyboard::isKeyPressed(minimap_size_increase)) {
		mini_map->changeParameter(- dt * config::mini_map::RESIZE_SPEED);
	} else if (sf::Keyboard::isKeyPressed(minimap_size_decrease)) {
		mini_map->changeParameter(dt * config::mini_map::RESIZE_SPEED);
	}
}