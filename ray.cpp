#include "vec3.h"
#include "ray.h"

Vec3 color(Ray const& ray) {
	Vec3 unitDirection = unitVector(ray.direction());

	float t = 0.5 * (unitDirection.y() + 1.0);
	return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t*Vec3(0.5, 0.7, 1.0);
}

