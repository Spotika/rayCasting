#include "Player.h"
#include <numbers>
#include <iostream>
#include "Config.h"
#include <cmath>


void Player::update() {
	// fixme
}

void Player::moveTo(sf::Vector2f target_pos) {
	position = target_pos;
}

float Player::getOrientation() {
	return orientation;
}

sf::Vector2f Player::getPosition() {
	return position;
}

void Player::move(sf::Vector2f diff_pos) {
	position.x += diff_pos.x;
	position.y += diff_pos.y;
}

void Player::rotate(float orientation_diff) {
	orientation += orientation_diff;

	// угол от 0 до 2х пи
	if (orientation > std::numbers::pi * 2) {
		orientation -= std::numbers::pi * 2;
	}
	else if (orientation < 0) {
		orientation += std::numbers::pi * 2;
	}

}

void Player::rotateTo(float orientation) {
	this->orientation = orientation;
}

float Player::getRotatingSpeed() {
	return rotating_speed;
}

float Player::getMovingSpeed() {
	return moving_speed;
}


void Player::drawOnMiniMap(MiniMap* mini_map) {
	// игрок представляет собой круг и линию , смотрящую по направлению взгляда
	
	int radius = 3;
	int length = 20;

	sf::Vector2f rel = mini_map->getRealativePosition(getPosition());

	sf::RenderTexture* render_texture = mini_map->getRenderTexture();

	sf::CircleShape shape(radius);
	shape.setFillColor(config::color::green);
	shape.setPosition(rel.x - radius, rel.y - radius);
	
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(rel.x, rel.y)),
		sf::Vertex(sf::Vector2f(rel.x + std::cos(orientation) * length, rel.y + std::sin(orientation) * length)),
	};

	line[0].color = config::color::green;
	line[1].color = config::color::green;


	render_texture->draw(shape);
	render_texture->draw(line, 2, sf::Lines);
};