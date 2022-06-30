#pragma once
#include"ray.h"
#include"vec.h"

class material;

struct hitpoint
{
	double t;
	Vec p;
	Vec normal;
	material* mat_ptr;
};

class hitable
{
public:
	virtual bool hit(ray& r, double t_min, double t_max, hitpoint& rec) const = 0;
};

