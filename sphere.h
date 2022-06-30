#pragma once
#include"material.h"

class sphere:public hitable
{
public:
	sphere() {};
	sphere(Vec p, double r, material* m) : center(p), radius(r), mat(m) {};
	virtual bool hit(ray& r, double t_min, double t_max, hitpoint& rec) const;
	double radius;
	Vec center;
	material* mat;
};

class sphereList :public sphere
{
public:
	sphereList(hitable** l, int spheresize) :list(l), length(spheresize) {};
	virtual bool hit(ray& r, double t_min, double t_max, hitpoint& rec) const;
	hitable * *list;
	int length;

};

