#include <iostream>
#include <iomanip>

#include "vec3.hpp"
#include "color.hpp"


//Listening to user48736353001 by Aphex Twin
//while writing this :)

int main() {

	//Image
	int const width =  4096;
	int const height = 4096;

	std::cout << "P3\n" << width << ' ' << height << "\n255\n";

	//As percent
	int prog = 0;
	int outInterval = static_cast<int>(height / 100);

	for (int i = height - 1; i >= 0; i--) {
		for (int j = 0; j < width; j++) {

			color pixelColor(double(i) / (width-1), double(j) / (height-1), 0.25);
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