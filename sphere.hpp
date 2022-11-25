
#include "vec3.hpp"
#include "hittable.hpp"

class Sphere : public hittable {
	point3 center;
	double radius;
	
public:
	Sphere() {}
	Sphere(point3 cen, double r) : center{cen}, radius{r} {}

	bool hit(ray const& r, double tMin, double tMax);
};