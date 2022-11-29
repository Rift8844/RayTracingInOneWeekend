
#include "hittable.hpp"

bool hittableList::hit(ray const& r, double tMin, double tMax, HitRecord& record) const {
	HitRecord tmpRec;
	bool hitOccured = false;
	double closest = tMax;

	for (auto const& obj : objects) {
		if (obj->hit(r, tMin, closest, tmpRec)) {
			hitOccured = true;
			closest = tmpRec.t;
			//hittable::record is set inside hit() in other objects
			record = tmpRec;
		}
	}

	return hitOccured;
}