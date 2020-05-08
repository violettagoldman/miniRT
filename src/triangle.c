#include "../rt.h"

int		triangle_hit(t_triangle tr, double min, double max, t_hit *hit, t_ray ray)
{
	(void)min;
	(void)max;
	t_vec v0v1 = vec_sub(tr.second, tr.first);
	t_vec v0v2 = vec_sub(tr.third, tr.first);
	t_vec n = vec_cross(v0v1, v0v2);
	double x = vec_dot(n, vec_norm(ray.d));
	if (fabs(x) < 1e-2)
		return (0);
	double d = vec_dot(n, tr.first);
	double t = (vec_dot(n, ray.o) + d) / x;
	if (t < 0)
		return (0);
	//printf("%f\n", vec_len(vec_norm(ray.d)));
	t_vec p = vec_add(ray.o, vec_mult(vec_norm(ray.d), t));
	//vec_print(p);
	//p = vec_at(ray, t);
	t_vec c;
	t_vec edge = vec_sub(tr.second, tr.first);
	t_vec vp = vec_sub(p, tr.first);
	c = vec_cross(edge, vp);
	if (vec_dot(n, c) < 0)
		return (0);
	t_vec edge1 = vec_sub(tr.third, tr.second);
	t_vec vp1 = vec_sub(p, tr.second);
	c = vec_cross(edge1, vp1);
	if (vec_dot(n, c) < 0)
		return (0);
	t_vec edge2 = vec_sub(tr.first, tr.third);
	t_vec vp2 = vec_sub(p, tr.third);
	c = vec_cross(edge2, vp2);
	if (vec_dot(n, c) < 0)
		return (0);
	hit->t = t;
	vec_print(vec_cross(vec_new(7, 6, 4), vec_new(2, 1, 3)));
	hit->p = p;
	return (1);
}

t_vec	triangle_norm(t_triangle tr)
{
	return (vec_cross(vec_sub(tr.second, tr.first), vec_sub(tr.third, tr.first)));
}
