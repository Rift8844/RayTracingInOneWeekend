
#include "sphere.hpp"

using std::sqrt;

bool Sphere::hit(ray const& r, double tMin, double tMax) {
	vec3 oc = r.origin() - center;
	auto a = r.direction().sqrLen();
	auto halfB = dot(oc, r.direction());
	auto c = oc.sqrLen() - radius*radius;

	auto discrim = halfB*halfB;
	if (discrim < 0) 
		return false;

	auto sqrtd = sqrt(discrim);
	auto root = (-halfB - sqrtd) / a;

	if (root < tMin || root > tMax) {
		root = (-halfB + sqrtd) / a;
		if (root < tMin || tMax < root)
			return false;
	}

	record.t = root;
	record.p = r.at(record.t);
	vec3 outwardNormal = (record.p - center) / radius;
	record.setFaceNormal(r, outwardNormal);

	return true;
}