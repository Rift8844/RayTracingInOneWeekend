#include <iostream>
#include <iomanip>

int main() {

	//Image
	int const width =  4096;
	int const height = 4096;

	std::cout << "P3\n" << width << ' ' << height << "\n255\n";

	int outInterval = static_cast<int>(height / 100);
	int progPcnt = 0;

	for (int i = height - 1; i >= 0; i--) {
		for (int j = 0; j < width; j++) {

			auto r = double (i) / (width - 1);
			auto g = double (j) / (height - 1);
			auto b = 0.25;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			std::cout << ir << ' ' << ig << ' ' << ib << '\n';
		}


		if ((height-i) % outInterval == 0 && progPcnt < 100) {
			progPcnt++;
			std::cerr << "Progress: " << progPcnt << "%" << std::endl;
		}
	}

	std::cerr << "Writing to disk..." << std::endl;

	return 0;
}