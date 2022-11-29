#include <iostream>
#include <iomanip>
#include <memory>

#include "vec3.hpp"
#include "color.hpp"
#include "ray.hpp"
#include "hittable.hpp"
#include "sphere.hpp"
#include "utility.hpp"

namespace StdColor {
	color Red(1, 0, 0);
	color Green(0, 1, 0);
	color Blue(0, 0, 1);
	color White(1, 1, 1);
};

//Lol is this good or bad idk
using namespace StdColor;

//idk ig I like this forward declarations lol
double hitSphere(point3 const& center, double radius, ray const& r);

color rayColor(ray const& r, hittable const& world) {
	HitRecord rec;

	if (world.hit(r, 0, inf, rec)) {
		return 0.5*color(rec.normal + White);
	}

	vec3 unitDirection = unitVec(r.direction());
	auto t = 0.5*(unitDirection.y() + 1.0);

	return (1.0-t)*White + t*color(0.5, 0.7, 1.0);
}


double hitSphere(point3 const& center, double radius, ray const& r) {
	vec3 oc = r.origin() - center;
	auto a = dot(r.direction(), r.direction());
	auto halfB = dot(oc, r.direction());
	auto c = oc.sqrLen() - radius*radius;
	auto discrim = halfB*halfB - a*c;

	if (discrim < 0) {
		return -1.0;
	} else {
		return (-halfB - sqrt(discrim)) / a;
	}
}

//Listening to Frequences by LFO now

int main() {

	//Image
	auto const aspectRatio = 16.0 / 9.0;
	//Consider renaming to imageWidth (and height)???
	int const width =  512;
	int const height = static_cast<int>(width / aspectRatio);

	//World
	hittableList world;
	world.add(std::make_shared<Sphere>(point3{0, 0, -1}, 0.5));
	world.add(std::make_shared<Sphere>(point3{0, -100.5, -1}, 100));

	//Camera
	double viewportH = 2.0;
	double viewportW = aspectRatio * viewportH;
	double focalLength = 1.0;

	vec3 origin = point3(0, 0, 0);
	vec3 horizontal = vec3(viewportW, 0, 0);
	vec3 vertical = vec3(0, viewportH, 0);
	//Bottom left
	vec3 leftCorner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focalLength);

	//Render
	std::cout << "P3\n" << width << ' ' << height << "\n255\n";


	//Progress as percentage
	int prog = 0;
	int outInterval = static_cast<int>(height / 100);

	for (int i = height - 1; i >= 0; i--) {
		for (int j = 0; j < width; j++) {

			double u = double(j) / (width - 1);
			double v = double(i) / (height - 1);

			//Second argument transposes pixel position into point 
			ray r(origin, leftCorner + u*horizontal + v*vertical - origin);
			color pixelColor = rayColor(r, world);
			
			outColor(std::cout, pixelColor);
		}



		if ((height-i) % outInterval == 0 && prog < 100) {
			prog++;
			std::cerr << "Progress: " << prog << "%" << std::endl;
		}
	}

	std::cerr << "\nDone processing; Writing to disk." << std::endl;

	return 0;
}