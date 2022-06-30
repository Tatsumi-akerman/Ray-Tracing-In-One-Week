#include "material.h"

double drand1000()
{
	return double(rand() % 1000) / 1000;
}

Vec rand_unit_sphere()
{
	Vec rand_point;
	do {
		rand_point = 2.0 * Vec(drand1000(), drand1000(), drand1000()) - Vec(1, 1, 1);
	} while (dot(rand_point, rand_point) >= 1);
	return rand_point;
}

Vec color(ray& Ray, hitable* world, int depth)
{
	if (Ray.begin == Vec(0, 0, 0) && Ray.direct == Vec(0, 0, 0))
	{
		return Vec(0, 0, 0);
	}
	hitpoint rec;
	if (world->hit(Ray, 0.001, 10000.0, rec))
	{
		ray_list scattered;
		Vec refl_attention;
		Vec refr_attention;
		if (depth < 50 && rec.mat_ptr->scatter(Ray, rec, refl_attention, refr_attention, scattered))
		{
			if (dot(scattered.reflex.direct, rec.normal) > 0)
				return refl_attention * color(scattered.reflex, world, depth + 1) + refr_attention * color(scattered.refract, world, depth + 1);
			else
				return Vec(0, 0, 0);
		}
		else
		{
			return Vec(0, 0, 0);
		}
	}
	Vec direct = Ray.direct;
	direct.unit();
	double k = 0.5 * (direct.y() + 1);
	Vec temp = (1 - k) * Vec(1, 1, 1) + k * Vec(0.5, 0.7, 1.0);
	return temp;
}

bool lambertain::scatter(const ray& r_in, const hitpoint& rec, Vec& refl_attention, Vec& refr_attention, ray_list& scattered) const
{
	Vec target = rec.normal + rand_unit_sphere();
	scattered.reflex = ray(rec.p, target);
	scattered.refract = ray(Vec(0, 0, 0), Vec(0, 0, 0));
	refl_attention = refl_albedo;
	refr_attention = Vec(0, 0, 0);
	return true;
}

Vec reflect(const Vec& r_in, const Vec& norm)
{
	return r_in - 2 * dot(r_in, norm) * norm;
}

bool refract1(const Vec& r_in, const Vec& norm, double n, Vec& refracted)
{
	Vec r = unitVec(r_in);
	double c1 = -dot(r, norm);
	double c2_2 = 1 - n * n * (1 - c1 * c1);
	if (c2_2 > 0)
	{
		refracted = n * (r + c1 * norm) - sqrt(c2_2) * norm;
		return true;
	}
	return false;
}

bool matal::scatter(const ray& r_in, const hitpoint& rec, Vec& refl_attention, Vec& refr_attention, ray_list& scattered) const
{
	Vec reflected = reflect(unitVec(r_in.direct), rec.normal);
	scattered.reflex = ray(rec.p, reflected + fuzz * rand_unit_sphere());
	scattered.refract = ray(Vec(0, 0, 0), Vec(0, 0, 0));
	refl_attention = refl_albedo;
	refr_attention = Vec(0, 0, 0);
	return (dot(scattered.reflex.direct, rec.normal) > 0);
}

double schlick(double cosine, double ref_idx)
{
	double r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0 * r0;
	return r0 + (1 - r0) * pow((1 - cosine), 0.5);
}

bool dielectric::scatter(const ray& r_in, const hitpoint& rec, Vec& refl_attention, Vec& refr_attention, ray_list& scattered) const
{
	Vec refracted;
	Vec reflected = reflect(unitVec(r_in.direct), rec.normal);
	Vec out_norm;
	double n;
	double reflect_prob;
	double cosine;
	if (dot(r_in.direct, rec.normal) < 0)
	{
		out_norm = rec.normal;
		n = 1.0 / ref_idx;
		cosine = -dot(r_in.direct, rec.normal) / r_in.direct.Length();
	}
	else
	{
		out_norm = -rec.normal;
		n = ref_idx;
		cosine = ref_idx * dot(r_in.direct, rec.normal) / r_in.direct.Length();
	}
	if (refract1(r_in.direct, out_norm, n, refracted))
	{
		reflect_prob = schlick(cosine, ref_idx);
		scattered.refract = ray(rec.p, refracted);
	}
	else
	{
		scattered.refract = ray(Vec(0, 0, 0), Vec(0, 0, 0));
		reflect_prob = 1.0;
	}
	refl_attention = Vec(reflect_prob, reflect_prob, reflect_prob);
	refr_attention = Vec(1.0 - reflect_prob, 1.0 - reflect_prob, 1.0 - reflect_prob);
	scattered.reflex= ray(rec.p, reflected);
	return true;
}