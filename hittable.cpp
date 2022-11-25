
#include "hittable.hpp"

bool hittableList::hit(ray const& r, double tMin, double tMax) {
	bool hitOccured = false;

	double closest = tMax;

	for (auto const& obj : objects) {
		if (obj->hit(r, tMin, closest)) {
			hitOccured = true;
			closest = record.t;
		}
	}

	return hitOccured;
}