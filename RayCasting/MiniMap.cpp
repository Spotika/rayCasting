#include "MiniMap.h"
#include "Config.h"
#include "AbstractEntity.h"
#include "AbstractLevel.h"
#include "IDrawableOnMiniMap.h"
#include "Screen.h"
#include <iostream>


MiniMap::MiniMap(AbstractLevel* level, sf::Vector2<int> position, int width, int height) {
	this->level = level;
	this->position = position;
	this->width = width;
	this->height = height;
	render_texture = new sf::RenderTexture;

	// ������������� � ���� ��� - �� �� ���, �� ������
	if (!render_texture->create(width, height)) {
		throw;
	}
}

void MiniMap::show() {
	render_texture->clear(config::color::grey);

	// ��������� ���������
	for (AbstractEntity* entity : level->entities) {
		// �������� �� ���������� ����������
		IDrawableOnMinimap* drawable = dynamic_cast<IDrawableOnMinimap*> (entity);

		if (drawable != nullptr) {
			drawable->drawOnMiniMap(this);
		}
	}

	// ��������� �������� TODO

	// ��������� ��������� �� ������
	sf::Sprite* to_blit = new sf::Sprite(render_texture->getTexture());
	to_blit->setPosition(position.x, position.y);
	Screen::getInstance()->getRenderWindow()->draw(*to_blit);
}

sf::Vector2<double> MiniMap::getRealativePosition(sf::Vector2<double> pos) {
	sf::Vector2<double> res{0, 0};

	res.x = ((double)width / level->getWidth()) * pos.x;
	res.y = ((double)height / level->getHeight()) * pos.y;

	return res;
}

sf::RenderTexture* MiniMap::getRenderTexture() {
	return render_texture;
}