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

	// отрисовка пола
	sf::RectangleShape floor({ (float)config::window::width, (float)config::window::height / 2 });
	floor.setPosition(0, config::window::height / 2);
	floor.setFillColor(config::game::FLOOR_COLOR);
	window->draw(floor);
	// отрисовка неба
	sf::RectangleShape sky({ (float)config::window::width, (float)config::window::height / 2 });
	sky.setPosition(0, 0);
	sky.setFillColor(config::game::SKY_COLOR);
	window->draw(sky);

	// отрисовка стен
	float step = config::window::width / config::render::RAYS_NUM;
	for (RayCaster::Intersection* intersection : intersections) {

		float dist = intersection->getDistance();
		dist = dist * std::cos(intersection->ray.orientation - player->getOrientation());

		float height = config::render::MAGIC_CONSTANT / dist;
		float y = config::window::height / 2 - height / 2;

		// ограничение прорисовки
		if (dist < config::render::VIEW_DISTANCE) {


			// отрисовка
			float x = step * intersection->ray.num;
			float height = config::render::MAGIC_CONSTANT / dist;
			float y = config::window::height / 2 - height / 2;


			sf::RectangleShape shape({step, height});
			shape.setPosition({ x, y });

			// работа с цветом
			sf::Color color = config::game::WALL_COLOR;
			float k = 1 - dist / config::render::VIEW_DISTANCE;

			color.r *= k;
			color.g *= k;
			color.b *= k;

			shape.setFillColor(color);
		
			window->draw(shape);			
		}

		
		// удаление ненужной памяти 
		delete intersection;
	};
}