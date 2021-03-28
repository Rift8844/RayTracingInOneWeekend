#ifndef RAYH
#define RAYH

struct Ray {
	Vec3 org;
	Vec3 dir;

	Ray(const Vec3& a, const Vec3& b) :
	org{a}, dir{b} {}

	Vec3 origin() const { return org; }
	Vec3 direction() const { return dir; }
	Vec3 pointAtParam(float t) const { return org + dir*t; }
};


#endif