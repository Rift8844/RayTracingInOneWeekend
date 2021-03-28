#include <math.h>
#include <cstdlib>
#include <iostream>
#include "vec3.h"

inline void Vec3::makeUnitVector() {
	float k = 1.0 / length();
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}

inline Vec3 operator+(Vec3 const& v1, Vec3 const& v2) {
	return Vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}
inline Vec3 operator-(Vec3 const& v1, Vec3 const& v2) {
	return Vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}
inline Vec3 operator*(Vec3 const& v1, Vec3 const& v2) {
	return Vec3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}
inline Vec3 operator/(Vec3 const& v1, Vec3 const& v2) {
	return Vec3(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}

inline Vec3 operator*(float t, Vec3 const& v) {
	return Vec3(v[0] * t, v[1] * t, v[2] * t);
}
inline Vec3 operator/(float t, Vec3 const& v) {
	return Vec3(v[0] / t, v[1] / t, v[2] / t);
}

inline float dot(Vec3 const& v1, Vec3 const& v2) {
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

inline Vec3 cross(Vec3 const& v1, Vec3 const& v2) {
	return Vec3( v1[1]*v2[2] - v1[2]*v2[1],
				-v1[0]*v2[2] + v1[2]*v2[0], 
				v1[0]*v2[1] - v1[1]*v2[0]
				);
}

inline Vec3& Vec3::operator+=(const Vec3& v) {
	e[0] += v[0];
	e[1] += v[1];
	e[2] += v[2];
	return *this;
}
inline Vec3& Vec3::operator-=(const Vec3& v) {
	e[0] -= v[0];
	e[1] -= v[1];
	e[2] -= v[2];
	return *this;
}
inline Vec3& Vec3::operator*=(const Vec3& v) {
	e[0] *= v[0];
	e[1] *= v[1];
	e[2] *= v[2];
	return *this;
}
inline Vec3& Vec3::operator/=(const Vec3& v) {
	e[0] /= v[0];
	e[1] /= v[1];
	e[2] /= v[2];
	return *this;
}

inline Vec3& Vec3::operator*=(const float t) {
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}
inline Vec3& Vec3::operator/=(const float t) {
	e[0] /= t;
	e[1] /= t;
	e[2] /= t;
	return *this;
}

inline Vec3 unitVector(Vec3 v) {
	return v / v.length();
}


inline std::istream& operator>>(std::istream& is, Vec3& t) {
	return is >> t[0] >> t[1] >> t[2];
}


inline std::ostream& operator>>(std::ostream& os, Vec3& t) {
	//OS, fo LIFE! - Big Time Tommy
	return os << t[0] << ' ' << t[1] << ' ' << t[2];
}

