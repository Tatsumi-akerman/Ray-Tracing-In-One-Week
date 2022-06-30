#include "camera.h"

Vec rand_len()
{
	Vec p;
	do {
		p = 2.0 * Vec(drand1000(), drand1000(), 0) - Vec(1, 1, 0);
	} while (dot(p, p) >= 1.0);
	return p;
}

camera::camera(Vec lookfrom, Vec lookat, Vec vup, double fview, double aspect, double aperture)
{
	double focus_dist = (lookfrom - lookat).Length();
	len_radius = aperture / 2;
	double theta = fview * PI / 180;
	double half_height = tan(theta / 2) * focus_dist;
	double half_wigth = aspect * half_height;
	origin = lookfrom;
	w = unitVec(lookfrom - lookat);
	u = unitVec(cross(vup, w));
	v = unitVec(cross(w, u));
	low_left = origin - half_height * v - half_wigth * u - focus_dist * w;
	heigth = 2 * half_height * v;
	wigth = 2 * half_wigth * u;
}

ray camera::get_ray(double s, double t)
{
	Vec rd = len_radius * rand_len();
	Vec offset = rd.x() * u + rd.y() * v;
	return ray(origin + offset, low_left + s * heigth + t * wigth - origin - offset);
}