#ifndef RAYH
#define RAYH

#include "vec3.h"

struct Ray {
	Vec3 origin;
	Vec3 direction;

	Ray(const Vec3& org, const Vec3& dir) :
	origin{org}, direction{dir} {}

	Vec3 origin() const { return origin; }
	Vec3 direction() const { return direction; }
	Vec3 pointAtParam(float t) const { return origin + direction*t; }
};


#endif