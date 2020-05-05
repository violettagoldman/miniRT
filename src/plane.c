#include "../rt.h"

int	plane_hit(t_plane p, double min, double max, t_hit *hit, t_ray ray)
{
	double t;
	double denom;
	t_vec tmp;

	denom = vec_dot(p.norm, ray.d);
	if (denom > 1e-6)
	{
		tmp = vec_sub(p.vec, ray.o);
		t = vec_dot(p.norm, tmp) / denom;
		if (t >= min && t <= max)
		{
			hit->t = t;
			hit->p = vec_at(ray, hit->t);
			return (t >= 0);
		}
	}
	return (0);
}
