#include"all.h"

double dx[5] = { 0,0.5,0.5,-0.5,-0.5 };
double dy[5] = { 0,0.5,-0.5,0.5,-0.5 };

int main() {
	std::ofstream out("focus.ppm");
	int m = 400, n = 200;
	out << "P3\n" << m << " " << n << "\n255\n";

	camera c1(Vec(0, 0, 1), Vec(0, 0, -1), Vec(0, 1, 0), 90, double(m) / n, 0.001);
	hitable* list[4];
	list[0] = new sphere(Vec(0.0, 0.0, -1.0), 0.5, new lambertain(Vec(0.8, 0.3, 0.3)));
	list[1] = new sphere(Vec(0.0, -100.5, -1.0), 100, new lambertain(Vec(0.8, 0.3, 0)));
	list[2] = new sphere(Vec(1, 0, -1.0), 0.5, new matal(Vec(0.8, 0.6, 0.2), 0.2));
	list[3] = new sphere(Vec(-1, 0, -1.0), 0.5, new dielectric(1.5));
	sphereList* world = new sphereList(list, 4);
	for (int i = n-1; i >= 0; --i)
	{
		for (int j = 0; j < m; ++j)
		{
			Vec col(0, 0, 0);
			for (int temp = 0; temp < 5; ++temp)
			{
				double dheight = double(i + dx[temp]) / double(n);
				double dwigth = double(j + dy[temp]) / double(m);
				ray Ray = c1.get_ray(dheight, dwigth);
				col += color(Ray, world, 0);
			}

			col /= 5;
			int r = int(255.99 * sqrt(col[0]));
			int g = int(255.99 * sqrt(col[1]));
			int b = int(255.99 * sqrt(col[2]));
			out << r << " " << g << " " << b << std::endl;
		}
	}
	delete world;
	delete list[0];
	delete list[1];
	delete list[2];
	delete list[3];
	return 0;
}