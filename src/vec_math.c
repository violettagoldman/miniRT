#include "../inc/vec.h"
#include "math.h"

t_vec	vec_norm(t_vec vec)
{
	double mg;

	mg = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (vec_div(vec, mg));
}

t_vec	vec_set(t_vec vec, double x, double y, double z)
{
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec	new_vec(double x, double y, double z)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
