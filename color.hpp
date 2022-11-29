
#pragma once

#include <iostream>
#include "vec3.hpp"

void outColor(std::ostream& out, color pxl) {
	//Expand range to 256 range
	out << static_cast<int>(255.99 * pxl.x()) << ' ' <<
	static_cast<int>(255.99 * pxl.y()) << ' ' <<
	static_cast<int>(255.99 * pxl.z()) << '\n';
}

