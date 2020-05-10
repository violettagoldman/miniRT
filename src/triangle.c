#include "../rt.h"

int		triangle_hit(t_triangle tr, double min, double max, t_hit *hit, t_ray ray)
{
	(void)min;
	(void)max;
	/*vec_print(tr.third);
	t_vec v0v1 = vec_sub(tr.second, tr.first);
	t_vec v0v2 = vec_sub(tr.third, tr.first);
	t_vec n = vec_cross(v0v1, v0v2);
	double x = vec_dot(n, ray.d);
	if (fabs(x) < 1e-6)
		return (0);
	double d = vec_dot(n, tr.first);
	double t = (vec_dot(n, ray.o) + d) / x;
	if (t < 0)
		return (0);
	t_vec p = vec_add(ray.o, vec_mult(ray.d, t));
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
	printf("%f\n", t);
	hit->p = p;
	return (1);*/
	//t_vec tvec;
	//t_vec v0v1 = vec_sub(tr.second, tr.first);
	//t_vec v0v2 = vec_sub(tr.third, tr.first);
	/*if ((vec_dot(v0v1, (pvec = vec_cross(ray.d, v0v2))) > 1e-8 &&
		vec_dot(v0v1, pvec) < 1e-8 )||
		(vec_dot((tvec = vec_sub(ray.o, tr.first)), pvec) *
			(1 / vec_dot(v0v1, pvec)) < 0 || vec_dot(tvec, pvec) *
				(1 / vec_dot(v0v1, pvec)) > 1))
		return (0);
	t_vec qvec;
	qvec = vec_cross(tvec, v0v1);
	if (vec_dot(ray.d, qvec) * (1 / vec_dot(v0v1, pvec)) < 0 ||
		vec_dot(tvec, pvec) * (1 / vec_dot(v0v1, pvec)) +
			vec_dot(ray.d, qvec) * (1 / vec_dot(v0v1, pvec)) > 1)
		return (0);*/
	/*t_vec pvec = vec_cross(ray.d, v0v2);
	double det = vec_dot(v0v1, pvec);
	if (fabs(det) < 1e-6)
		return (0);
	float inv_det = 1 / det;
	t_vec tvec = vec_sub(ray.o, tr.first);
	double u = vec_dot(tvec, pvec) * inv_det;
	if (u < 0 || u > 1)
		return (0);
	t_vec qvec = vec_cross(tvec, v0v1);
	double v = vec_dot(ray.d, qvec) * inv_det;
	if (v < 0 || u + v > 1)
		return (0);
	double t = vec_dot(v0v2, qvec) * inv_det;
	//hit->t = vec_dot(v0v2, qvec) * (1 / vec_dot(v0v1, pvec));*/
	t_vec e1 = vec_sub(tr.second, tr.first);
	t_vec e2 = vec_sub(tr.third, tr.first);
	t_vec h = vec_cross2(ray.d, e2);
	double a = vec_dot(e1, h);
	if (fabs(a) < 1e-6)
		return (0);
	double f = 1 / a;
	t_vec s = vec_sub(ray.o, tr.first);
	double u = f * vec_dot(s, h);
	if (u < 0 || u > 1)
		return (0);
	t_vec q = vec_cross2(s, e1);
	double v = f * vec_dot(ray.d, q);
	if (v < 0 || u + v > 1)
		return (0);
	double t = f * vec_dot(e2, q);
	if (t < 1e-6)
		return (0);
	hit->t = t;
	hit->p = vec_at(ray, hit->t);
	return (t > min && t < max);
}

t_vec	triangle_norm(t_triangle tr)
{
	return (vec_norm(vec_cross2(vec_sub(tr.second, tr.first), vec_sub(tr.third, tr.first))));
}
