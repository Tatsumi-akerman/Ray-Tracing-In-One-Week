#include "sphere.h"

bool sphere::hit(ray& r1, double t_min, double t_max, hitpoint& rec) const
{
	Vec oc = r1.begin - center;
	double a = dot(r1.direct, r1.direct);
	double b = 2 * dot(r1.direct, oc);
	double c = dot(oc, oc) - radius * radius;
	double out = b * b - 4 * a * c;
	if (out > 0)
	{
		double temp = (-b - sqrt(out)) / (2 * a);
		if (temp<t_max && temp>t_min)
		{
			rec.t = temp;
			rec.p = r1.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.mat_ptr = mat;
			return true;
		}
		temp = (-b + sqrt(out)) / (2 * a);
		if (temp<t_max && temp>t_min)
		{
			rec.t = temp;
			rec.p = r1.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.mat_ptr = mat;
			return true;
		}
	}
	return false;
}

bool sphereList::hit(ray& r, double t_min, double t_max, hitpoint& rec) const
{
	bool hited = false;
	hitpoint temp;
	for (int i = 0; i < length; ++i)
	{
		if (list[i]->hit(r, t_min, t_max, temp))
		{
			rec = temp;
			t_max = temp.t;
			hited = true;
		}
	}
	return hited;
}
