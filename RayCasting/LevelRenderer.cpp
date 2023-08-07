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

		// ограничение проресовки
		if (dist < config::render::VIEW_DISTANCE) {

			// отрисовка
			float k = (1 - (dist / config::render::VIEW_DISTANCE));

			sf::RectangleShape shape({ step, config::window::height * k});
			int x = ceil(200 * k);
			shape.setPosition({ step * intersection->ray.num, (config::window::height - shape.getSize().y)/2.0f });
			shape.setFillColor({ sf::Uint8(x), sf::Uint8(x), sf::Uint8(x) }); // FIXME
		
			window->draw(shape);
		}
			
		// удаление ненужной памяти 
		delete intersection;
	};
	std::cout << "\n";
}