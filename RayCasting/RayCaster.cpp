#include "RayCaster.h"


void RayCaster::cast(sf::Vector2<int> start_point, int num_of_rays, float orientation, float fov) {

}

std::vector<RayCaster::Intersection>& RayCaster::getInstersections(std::vector<AbstractLevelPart*>& level_parts) {
	// FIXME
	std::vector<RayCaster::Intersection> x;
	return x;
}

bool RayCaster::Intersection::operator<(Intersection const& other) const {
	// FIXME
	return false;
}

float RayCaster::Intersection::getDistance() const {
	// FIXME
	return 0;
}
