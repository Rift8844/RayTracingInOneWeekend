
#pragma once

#include <cmath>
#include <iostream>
#include <array>

using std::sqrt;

class vec3 {

	std::array<double, 3> e;

public:
	vec3() : e{{0, 0, 0}} {}
	vec3(double e0, double e1, double e2) : e{{e0, e1, e2}} {}
	//do we need to definet this?
	//vec3(vec3 const& v) {}

	double x() const { return e[0]; }
	double y() const { return e[1]; }
	double z() const { return e[2]; }

	vec3 operator-() const { return vec3(-x(), -y(), -z()); }
	double operator[](int i) const { return e[i]; }
	double& operator[](int i) { return e[i]; }

	vec3& operator+=(vec3 const& v) {
		e[0] += v.x();
		e[1] += v.y();
		e[2] += v.z();
		return *this;
	}

	vec3& operator*=(double const t) {
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}

	vec3& operator/=(double const t) {
		return *this *= 1/t;
	}

	double length() const {
		return sqrt(sqrLen());
	}

	double sqrLen() const {
		return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
	}
};


using point3 = vec3;
using color = vec3;


//vec3 utilities

inline std::ostream& operator<<(std::ostream& out, vec3 const& v) {
	return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

//Lazy version of the tutorial implementation but it should work lmao
inline vec3 operator+(vec3 v, vec3 const& w) {
	v += w;
	return v;
}

inline vec3 operator-(vec3 v, vec3 const& w) {
	v += -w;
	return v;
}

inline vec3 operator*(vec3 const& v, vec3 const& w) {
	return vec3(v.x()*w.x(), v.y()*w.y(), v.z()*w.z());
}

inline vec3 operator*(vec3 const& v, double t) {
	return vec3(v.x()*t, v.y()*t, v.z()*t);
}


inline vec3 operator*(double t, vec3 const& v) {
	return v*t;
}

inline vec3 operator/(vec3 v, double const t) {
	//Why not v/t ?
	return (1/t) * v;
}

inline double dot(vec3 const& v, vec3 const& w) {
	return v.x()*w.x() + v.y()*w.y() + v.z()*w.z();
}

inline vec3 cross(vec3 const& v, vec3 const& w) {
	return vec3(
		v.y() * w.z() - v.z() * w.y(),
		v.z() * w.x() - v.x() * w.z(),
		v.x() * w.y() - v.y() * w.x()
		);
}

inline vec3 unitVec(vec3 v) {
	return v / v.length();
}

