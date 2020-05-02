#include "../rt.h"

t_sphere	*create_sphere(t_vec c, double r, t_color color)
{
	t_sphere *sphere;

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sphere->c = c;
	sphere->r = r;
	sphere->col = color;
	return (sphere);
}

double	hit_sphere(t_sphere s, double min, double max, t_hit *hit, t_ray ray)
{
	t_vec oc = vec_sub(ray.o, s.c);
	double a = vec_dot(ray.d, ray.d);
	double half_b = vec_dot(oc, ray.d);
	double c = vec_dot(oc, oc) - s.r * s.r;
	double discriminant = half_b * half_b - a * c;

	if (discriminant > 0)
	{
		double root = sqrt(discriminant);
		double temp = (-half_b - root) / a;
		if (temp < max && temp > min)
		{
			hit->t = temp;
			hit->p = vec_at(ray, hit->t);
			t_vec norm = vec_div(vec_sub(hit->p, s.c), s.r);
			*hit = face_norm(*hit, ray, norm);
			return (1);
		}
		temp = (-half_b + root) / a;
		if (temp < max && temp > min)
		{
			hit->t = temp;
			hit->p = vec_at(ray, hit->t);
			t_vec norm = vec_div(vec_sub(hit->p, s.c), s.r);
			*hit = face_norm(*hit, ray, norm);
			return (1);
		}
	}
	return (0);
}

t_sphere	sphere_new(t_vec c, double r, t_color col)
{
	t_sphere s;

	s.c = c;
	s.r = r;
	s.col = col;
	return (s);
}

t_vec	sphere_norm(t_sphere s, t_vec pi)
{
	t_vec res;

	res = vec_sub(pi, s.c);
	vec_div(res, s.r);
	return (res);
}
