#include "../rt.h"

t_vec	vec_at(t_ray ray, double t)
{
	return (vec_add(ray.o, vec_mult(ray.d, t)));
}

void	vec_print(t_vec vec)
{
	printf("%f %f %f\n", vec.x, vec.y, vec.z);
}
