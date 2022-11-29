
#pragma once


#include "vec3.hpp"

class ray {
	point3 orig;
	point3 dir;

public:
	ray() {}
	ray(point3 const& origin, vec3 const& direction) : 
		orig{origin}, dir{direction} {}

	point3 origin() const { return orig; }
	vec3 direction() const { return dir; }

	point3 at(double t) const {
		return orig + dir*t;
	}
};
