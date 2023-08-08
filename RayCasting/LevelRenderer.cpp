#include "LevelRenderer.h"
#include <iostream>
#include "RayCaster.h"
#include "Screen.h"
#include "Config.h"


LevelRenderer::LevelRenderer(AbstractLevel* level, Player* player) : level{ level }, player{ player } {
	ray_caster = new RayCaster();
}

void LevelRenderer::render() {
	ray_caster->cast(player->getPosition(), config::render::RAYS_NUM, player->orientation, config::render::FOV);

	std::vector<RayCaster::Intersection*> intersections = ray_caster->getInstersections(level->level_parts);


	
	sf::RenderWindow* window = Screen::getInstance()->getRenderWindow();
	
	float step = config::window::width / config::render::RAYS_NUM;

	for (RayCaster::Intersection* intersection : intersections) {

		float dist = intersection->getDistance();
		dist = dist * std::cos(intersection->ray.orientation - player->getOrientation());


		// ограничение прорисовки
		if (dist < config::render::VIEW_DISTANCE) {


			// отрисовка
			float x = step * intersection->ray.num;
			float height = config::render::MAGIC_CONSTANT / dist;
			float y = config::window::height / 2 - height / 2;


			sf::RectangleShape shape({step, height});
			shape.setPosition({ x, y });

			// работа с цветом
			uint8_t color = 255 - (int)ceil(255 * (dist / config::render::VIEW_DISTANCE));

			shape.setFillColor({ color, color, color });
		
			window->draw(shape);			
		}

		
		// удаление ненужной памяти 
		delete intersection;
	};
}