#include "../rt.h"

int		square_hit(t_square sq, double min, double max, t_hit *hit, t_ray ray)
{
	double x0 = -0.1;
	double x1 = 0.1;
	double y0 = -0.1;
	double y1 = 0.1;
	sq.vec.z = 6;
	double t = (sq.vec.z - ray.o.z) / ray.d.z;
	if (t < min || t > max)
		return (0);
	double x = ray.o.x + t * ray.d.x;
	double y = ray.o.y + t * ray.d.y;
	if (x < x0 || x > x1 || y < y0 || y > y1)
		return (0);
	hit->t = t;
	hit->p = vec_at(ray, hit->t);
	return (1);
}
