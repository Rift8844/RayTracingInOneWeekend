
#pragma once

#include "vec3.hpp"
#include "ray.hpp"
#include <memory>
#include <vector>

struct HitRecord {
	point3 p;
	vec3 normal;
	double t;

	bool frontFace;

	inline void setFaceNormal(ray const& r, vec3 const& outwardNormal) {
		frontFace = dot(r.direction(), outwardNormal) < 0;
		normal = frontFace ? outwardNormal : -outwardNormal;
	}
};

class hittable {
protected:
	inline static HitRecord record{};

public:

	virtual bool hit(ray const& r, double tMin, double tMax) = 0;
};


//Should probably scrap this later bc it seems stupid
class hittableList : public hittable {
	std::vector<std::shared_ptr<hittable>> objects;

public:
	bool hit(ray const& r, double tMin, double tMax);
	hittableList();
	hittableList(std::shared_ptr<hittable> object) { add(object); }

	void clear() { objects.clear(); }
	void add(std::shared_ptr<hittable> object) { objects.push_back(object); }
};

