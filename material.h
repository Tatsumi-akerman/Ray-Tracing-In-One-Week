#pragma once
#include"vec.h"
#include"ray.h"
#include"hitable.h"
#include<random>

class material {
public:
	virtual bool scatter(const ray& r_in, const hitpoint& rec, Vec& refl_attention, Vec& refr_attention, ray_list& scattered) const = 0;
};

class lambertain:public material {
public:
	lambertain() {};
	lambertain(const Vec& v) :refl_albedo(v) {};
	virtual bool scatter(const ray& r_in, const hitpoint& rec, Vec& refl_attention, Vec& refr_attention, ray_list& scattered) const;
	Vec refl_albedo;
};

class matal :public material {
public:
	matal() {};
	matal(const Vec& v, double f) :refl_albedo(v) { if (f < 1) fuzz = f; else fuzz = 1; };
	virtual bool scatter(const ray& r_in, const hitpoint& rec, Vec& refl_attention, Vec& refr_attention, ray_list& scattered) const;
	Vec refl_albedo;
	double fuzz;
};

class dielectric :public material {
public:
	dielectric() {};
	dielectric(double f) :ref_idx(f) {};
	virtual bool scatter(const ray& r_in, const hitpoint& rec, Vec& refl_attention, Vec& refr_attention, ray_list& scattered) const;

	double ref_idx;
};

double drand1000();
Vec reflect(const Vec& r_in, const Vec& norm);
bool refract1(const Vec& r_in, const Vec& norm, double n, Vec& refracted);
Vec rand_unit_sphere();
Vec color(ray& Ray, hitable* world, int depth);
double schlick(double cosine, double ref_idx);
