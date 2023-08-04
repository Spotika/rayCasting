#include "Player.h"
#include <numbers>
#include <iostream>
#include "Config.h"

void Player::update() {
	// fixme
}

void Player::moveTo(sf::Vector2<double> target_pos) {
	position = target_pos;
}

double Player::getOrientation() {
	return orientation;
}

sf::Vector2<double> Player::getPosition() {
	return position;
}

void Player::move(sf::Vector2<double> diff_pos) {
	position.x += diff_pos.x;
	position.y += diff_pos.y;
}

void Player::rotate(double orientation_diff) {
	orientation += orientation_diff;

	// угол от 0 до 2х пи
	if (orientation > std::numbers::pi * 2) {
		orientation -= std::numbers::pi * 2;
	}
	else if (orientation < 0) {
		orientation += std::numbers::pi * 2;
	}

}

void Player::rotateTo(double orientation) {
	this->orientation = orientation;
}

double Player::getRotatingSpeed() {
	return rotating_speed;
}

double Player::getMovingSpeed() {
	return moving_speed;
}

void Player::drawOnMiniMap(MiniMap* mini_map) {
	// Fixme

	// Базовая отрисовка игрока
	sf::Vector2<double> rel = mini_map->getRealativePosition(getPosition());

	sf::RenderTexture* render_texture = mini_map->getRenderTexture();

	sf::CircleShape shape(5);
	shape.setFillColor(config::color::green);
	shape.setPosition(rel.x, rel.y);

	render_texture->draw(shape);

};