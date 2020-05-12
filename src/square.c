#include "../rt.h"

int		square_hit(t_square sq, double min, double max, t_hit *hit, t_ray ray)
{
	/*(void)min;
	(void)max;
	double alpha;
	double beta;
	double denom;
	t_vec point[4];
	sq.norm = vec_norm(sq.norm);
	points(sq, point);
	t_vec ab = vec_sub(point[1], point[0]);
	t_vec ac = vec_sub(point[2], point[0]);
	denom = -(vec_dot(sq.norm, sq.vec));
	double calc = vec_dot(ray.o, sq.norm) + denom;
	alpha = vec_dot(ray.d, sq.norm);
	beta = -(calc / alpha);
	if (beta <= 0)
		return (0);
	double t = beta;
	t_vec tmp = vec_mult(ray.d, t);
	t_vec p = vec_add(tmp, ray.o);
	t_vec ap = vec_sub(p, point[0]);
	alpha = vec_dot(ap, ab) / vec_dot(ab, ab);
	beta = vec_dot(ap, ac) / vec_dot(ac, ac);
	hit->t = t;
	hit->p = vec_at(ray, t);
	if (alpha >= 0 && alpha <= 1 && beta >=  0 && beta <= 1)
		return (1);
	return (0);*/
	//sq.norm = rotation(sq.norm, vec_new(rand() % 5, rand() % 5, rand() % 5));
	double a = vec_dot(vec_sub(ray.o, sq.vec), sq.norm);
	double b = vec_dot(ray.d, sq.norm);
	if (fabs(b) < 1e-6 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	double t1 = -a / b;
	t_vec d = vec_sub(vec_add(vec_mult(ray.d, t1), ray.o), sq.vec);
	double t2 = sq.size / 2;
	if (fabs(d.x) > t2 || fabs(d.y) > t2 || fabs(d.z) > t2)
		return (0);
	if (t1 > min && t1 < max)
	{
		hit->t = t1;
		hit->p = vec_at(ray, hit->t);
		return (1);
	}
	return (0);
}

void	points(t_square sq, t_vec p[4])
{
	double	size;

	size = sq.size / 2;
	p[0] = vec_new(size, size, 0);
	p[1] = vec_new(-size, size, 0);
	p[2] = vec_new(size, -size, 0);
	p[3] = vec_new(-size, -size, 0);
	p[0] = vec_add(rotation(p[0], sq.norm), sq.vec);
	p[1] = vec_add(rotation(p[1], sq.norm), sq.vec);
	p[2] = vec_add(rotation(p[2], sq.norm), sq.vec);
	p[3] = vec_add(rotation(p[3], sq.norm), sq.vec);
}
