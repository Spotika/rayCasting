#include "WallPolygon.h"
#include "Config.h"

part::WallPolygon::WallPolygon(std::vector<sf::Vector2f> points) {
	this->points.clear();
	for (sf::Vector2f point : points) {
		this->points.push_back(point);
		this->points.back().color = config::color::dark_green;
	}
}


void part::WallPolygon::drawOnMiniMap(MiniMap* mini_map) {


	sf::RenderTexture* render_texture = mini_map->getRenderTexture();

	render_texture->draw(&points[0], points.size(), sf::LinesStrip);

}

RayCaster::Intersection part::WallPolygon::getIntersection(RayCaster::Ray* ray) {
	return RayCaster::Intersection();
}
