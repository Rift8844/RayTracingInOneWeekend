
#pragma once

#include <cmath>
#include <limits>
#include <memory>

double constexpr inf = std::numeric_limits<double>::infinity();
//Eh it's good enough lol
double constexpr pi = 3.1415926535897932385;

inline double  degToRad(double deg) {
	return deg * pi / 180.0;
}
