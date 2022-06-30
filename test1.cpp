#include"test1.h"
void test1() {
	int nx = 400, ny = 200;
	std::ofstream OutImage("test1.ppm");
	OutImage << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny - 1; j >= 0; --j) {
		for (int i = 0; i < nx; ++i) {
			double dr = (double)i / (double)nx;
			double dg = (double)j / (double)ny;
			double db = 0.2;
			int r = (int)(255.99 * dr);
			int g = (int)(255.99 * dg);
			int b = (int)(255.99 * db);
			OutImage << r << " " << g << " " << b << std::endl;
		}
	}
}