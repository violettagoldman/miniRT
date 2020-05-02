#include "../rt.h"

t_vec	vec_norm(t_vec vec)
{
	double mg;

	mg = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (vec_div(vec, mg));
}

t_vec	vec_new(double x, double y, double z)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec	vec_cross(t_vec a, t_vec b)
{
	return vec_new(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

t_vec unit_vector(t_vec vec)
{
    return (vec_div(vec, vec_len(vec)));
}

double		vec_len(t_vec vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}
