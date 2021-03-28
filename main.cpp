#include <iostream>
#include "vec3.h"
#include "ray.h"


int main() { 
	int width = 1280;
	int height = 720;

	std::cout << "P3\n" << width << ' ' << height << "\n255\n";

	Vec3 lowerLeftCorner(-2, -1, -1);
	Vec3 horizontal(4, 0, 0);
	Vec3 vertical(0, 2, 0);
	Vec3 origin(0, 0, 0);

	for (int j = height-1; j >= 0; j++) {
		for (int i = 0;  i < width; i++) {
			float u = float(i) / float (width);
			float v = float(j) / float(height);

			Ray r(origin, lowerLeftcorner + u*horizontal + u*vertical);
			Vec3 col = color(r);

			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);

			std::cout << ir << ' ' << ig <<
			' ' << ib << '\n';
		}
	}
}