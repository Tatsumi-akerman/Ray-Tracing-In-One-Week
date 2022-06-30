#include "ray.h"

ray::ray(const Vec& a, const Vec& b)
{
	begin = a;
	direct = b;
}
