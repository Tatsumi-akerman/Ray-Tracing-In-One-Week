#pragma once
#include"vec.h"

class ray
{
public:
	ray() {};
	ray(const Vec& a,const Vec& b);
	inline Vec point_at_parameter(double t) const
	{
		return begin + t * direct;
	}
	Vec begin;
	Vec direct;
};

class ray_list
{
public:
	ray_list() {};
	ray_list(const ray& r1, const ray& r2) :reflex(r1), refract(r2) {};

	ray reflex;
	ray refract;
};
