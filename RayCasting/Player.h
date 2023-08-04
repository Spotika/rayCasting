#pragma once
#include "AbstractEntity.h"
#include "IControlled.h"
#include "IMoovable.h"
#include "Config.h"


class Player : public AbstractEntity, public IMoovable {
public:
	
	int moving_speed = config::player::BASE_MOVING_SPEED;
	double rotating_speed = config::player::BASE_ROTATING_SPEED;

	Player(sf::Vector2<double> positon, double orientation) : AbstractEntity{ positon, orientation } {};

	void update();

	void moveTo(sf::Vector2<double> target_pos);

	void move(sf::Vector2<double> diff_pos);

	void rotate(double orientation_diff);

	void rotateTo(double orientation);

	double getOrientation();

	double getMovingSpeed();

	double getRotatingSpeed();

	sf::Vector2<double> getPosition();
};