#pragma once
#include"vec.h"
#include"ray.h"
#include"material.h"

#define PI 3.14159265

class camera
{
public:
	camera();
	camera(Vec lookfrom, Vec lookat, Vec vup, double fview, double aspect, double aperture);
	ray get_ray(double s, double t);

	Vec origin;
	Vec low_left;
	Vec heigth;
	Vec wigth;
	Vec u, v, w;
	double len_radius;
};

Vec rand_len();

