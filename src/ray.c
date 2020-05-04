#include "../rt.h"

t_ray ray_get(t_camera c, double u, double v)
{
	return (ray_new(c.origin, vec_add(c.lower_left_corner,
		vec_add(vec_mult(c.horizontal, u), vec_mult(c.vertical, v)))));
}

t_ray ray_new(t_vec o, t_vec d)
{
	t_ray ray;

	ray.o = o;
	ray.d = d;
	return (ray);
}
