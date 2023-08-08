#include "MiniMap.h"
#include "Config.h"
#include "AbstractEntity.h"
#include "AbstractLevel.h"
#include "IDrawableOnMiniMap.h"
#include "Screen.h"
#include <iostream>
#include <cmath>


MiniMap::MiniMap(AbstractLevel* level, sf::Vector2<int> position, sf::Vector2<int> size) {
	this->level = level;
	this->position = position;
	this->width = size.x;
	this->height = size.y;
	render_texture = new sf::RenderTexture;

	// инициализация и если что - то не так, то ошибка
	if (!render_texture->create(width, height)) {
		throw;
	}
}

void MiniMap::show() {
	render_texture->clear(config::color::dark_grey);

	// отрисовка сущностей
	for (AbstractEntity* entity : level->entities) {
		// проверка на реализацию интерфейса
		IDrawableOnMinimap* drawable = dynamic_cast<IDrawableOnMinimap*> (entity);

		if (drawable != nullptr) {
			drawable->drawOnMiniMap(this);
		}
	}
	sf::RenderWindow* window = Screen::getInstance()->getRenderWindow();
	
	if (realative_target != nullptr) {
		sf::View view;

		int view_width = ceil(config::mini_map::size * view_size_fraction) / 2;
		int view_height = ceil(config::mini_map::size * view_size_fraction) / 2;

		view.setSize(view_width, view_height);
		view.setCenter(getRealativePosition(realative_target->position));
		render_texture->setView(view);
	}



	// Отрисовка объектов 
	for (AbstractLevelPart* part : level->level_parts) {
		IDrawableOnMinimap* drawable = dynamic_cast<IDrawableOnMinimap*> (part);

		if (drawable != nullptr) {
			drawable->drawOnMiniMap(this);
		}
	}


	// отрисовка миникарты на экране

	sf::Sprite* to_blit = new sf::Sprite(render_texture->getTexture());
	to_blit->setPosition(position.x, position.y);

	window->draw(*to_blit);

	delete to_blit;
}

sf::Vector2f MiniMap::getRealativePosition(sf::Vector2f pos) {
	sf::Vector2f res{0, 0};

	res.x = ((float)width / level->getWidth()) * pos.x;
	res.y = ((float)height / level->getHeight()) * pos.y;

	return res;
}

sf::RenderTexture* MiniMap::getRenderTexture() {
	return render_texture;
}

void MiniMap::setRealativeTraget(AbstractEntity* realative_target) {
	this->realative_target = realative_target;
}

void MiniMap::setParameter(float value) {
	view_size_fraction = value;
	view_size_fraction = std::max(0.1f, view_size_fraction);
	view_size_fraction = std::min(1.0f, view_size_fraction);
}

void MiniMap::changeParameter(float diff) {
	setParameter(view_size_fraction + diff);
}
