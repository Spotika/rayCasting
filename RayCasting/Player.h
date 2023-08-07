#pragma once
#include "AbstractEntity.h"
#include "IControlled.h"
#include "IMoovable.h"
#include "IDrawableOnMiniMap.h"
#include "Config.h"


class Player : public AbstractEntity, public IMoovable, public IDrawableOnMinimap  {
public:
	
	int moving_speed = config::player::BASE_MOVING_SPEED;
	float rotating_speed = config::player::BASE_ROTATING_SPEED;

	Player(sf::Vector2f positon, float orientation) : AbstractEntity{ positon, orientation } {};

	void update();

	void moveTo(sf::Vector2f target_pos);

	void move(sf::Vector2f diff_pos);

	void rotate(float orientation_diff);

	void rotateTo(float orientation);

	float getOrientation();

	float getMovingSpeed();

	float getRotatingSpeed();

	void drawOnMiniMap(MiniMap* mini_map);

	sf::Vector2f getPosition();
};