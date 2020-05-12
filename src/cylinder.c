#include "../rt.h"

/*int		cylinder_hit(t_cylinder cy, double min, double max, t_hit *hit, t_ray ray)
{
	(void)min;
	(void)max;
	t_vec c1;
	t_vec c2;

	c1 = vec_add(cy.vec, vec_mult(cy.norm, cy.h));
	c2 = vec_sub(cy.vec, vec_mult(cy.norm, cy.h));
	t_vec p = vec_new(ray.o.x - c1.x, ray.o.y - c1.y, ray.o.z - c1.z);
	double a = ray.d.x  * ray.d.x + ray.d.z * ray.d.z;
	double b = ray.d.x * p.x + ray.d.z * p.z;
	double c = p.x * p.x + p.z * p.z - (cy.d / 2) * (cy.d / 2);
	double delta = b * b - a * c;
	if (delta < 1e-6)
		return (0);
	double t = (-b - sqrt(delta)) / a;
	if (t <= 1e-6)
		return (0);
	double y = p.y + t * ray.d.y;
	if (y > cy.h + 1e-6 || y < -1e-6)
	{
		double dist;
		int b1 = base_hit(cy, ray, &dist, c1, c1);
		if (b1)
			t = dist;
		int b2 = base_hit(cy, ray, &dist, c2, c1);
		if (b2 && dist > 1e-6 && t >= dist)
			t = dist;
		hit->t = t;
		hit->p = vec_at(ray, hit->t);
		return (b1 || b2);
	}
	hit->t = t;
	hit->p = vec_at(ray, hit->t);
	return (1);
}

int		base_hit(t_cylinder cy, t_ray ray, double *dist, t_vec c, t_vec center)
{
	double radius;

	radius = cy.d / 2;
	t_vec norm = cylinder_norm(cy, c);
	t_vec p = vec_sub(ray.o, center);
	double d = -(norm.x * (c.x - center.x) + norm.y * (c.y - center.y) + norm.z * (c.z - center.z));
	double res = norm.x * ray.d.x + norm.y * ray.d.y + norm.z * ray.d.z;
	if (res == 0)
		return (0);
	double dist2 = - (norm.x * p.x + norm.y * p.y + norm.z * p.z + d) / res;
	if (dist2 < 1e-6)
		return (0);
	*dist = dist2;
	t_vec point;
	point = vec_new(p.x + dist2 * ray.d.x, p.y + dist2 * ray.d.y, p.z + dist2 * ray.d.z);
	if (point.x * point.x + point.z * point.z - radius * radius > 1e-6)
		return (0);
	return (1);
}*/

t_vec	cylinder_norm(t_cylinder cy, t_vec p)
{
	// double radius;
	//
	// cy.vec = vec_add(cy.vec, vec_mult(cy.norm, cy.h));
	// radius = cy.d / 2;
	// if (p.x < cy.vec.x + radius && p.x > cy.vec.x - radius &&
	// 	p.z < cy.vec.z + radius && p.z > cy.vec.z - radius)
	// {
	// 	if (p.y < cy.vec.y + cy.h + 1e-6 && p.y > cy.vec.y + cy.h - 1e-6)
	// 		return (vec_new(0, 1, 0));
	// 	if (p.y < cy.vec.y + 1e-6 && p.y > cy.vec.y - 1e-6)
	// 		return (vec_new(0, -1, 0));
	// }
	// t_vec c = vec_new(cy.vec.x, p.y, cy.vec.z);
	// t_vec v = vec_sub(p, c);
	// v = vec_norm(v);
	// return (v);
	t_vec	norm;
	t_vec	axe;
	t_vec	v1n;

	norm = vec_sub(p, cy.vec);
	v1n = vec_norm(cy.norm);
	axe = vec_mult(v1n, fabs(vec_dot(norm, v1n)));
	if (vec_dot(norm, cy.norm) < 0)
		axe = vec_mult(axe, -1);
	norm = vec_sub(norm, axe);
	norm = vec_norm(norm);
	return (norm);
}

static double	get_t(double t1, double t2, t_cylinder cy, t_ray r)
{
	double		l1;
	double		l2;

	l1 = vec_dot(vec_sub(vec_add(r.o, vec_mult(r.d, t1)), cy.vec), cy.norm);
	l2 = vec_dot(vec_sub(vec_add(r.o, vec_mult(r.d, t2)), cy.vec), cy.norm);
	if (t1 > 1e-6 && (t1 <= t2 || t2 < 1e-6) && fabs(l1) <= cy.h)
	{
		// cy->first = 1;
		// cy->d = l1;
		return (t1);
	}
	if (t2 > 1e-6 && fabs(l2) <= cy.h)
	{
		// cy->first = 0;
		// cy->d = l2;
		return (t2);
	}
	return (-1);
}

static double sqr(double x)
{
	return (x * x);
}

int		cylinder_hit(t_cylinder cy, double min, double max, t_hit *hit, t_ray ray)
{
	t_vec	x;
	double		a;
	double		b;
	double		d;
	double		r;

	r = cy.d / 2;
	x = vec_sub(ray.o, cy.vec);
	a = vec_dot(ray.d, ray.d) - sqr(vec_dot(ray.d, cy.norm));
	b = 2 * (vec_dot(ray.d, x) - vec_dot(ray.d, cy.norm) * vec_dot(x, cy.norm));
	d = vec_dot(x, x) - sqr(vec_dot(x, cy.norm)) - r * r;
	d = b * b - 4 * a * d;
	d = (fabs(d) < 1e-6) ? 0 :
	get_t((-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a), cy, ray);
	if (!(d > min && d < max))
		return (0);
	//i->shape = shape;
	hit->t = d;
	hit->p = vec_add(ray.o, vec_mult(ray.d, d));
	//i->normal = cyl_normal(&cy, i->hit);
	// x = cross(cy.norm, vector_xyz(1, 0, 0));
	// i->color = (cy.check == 1) ? checked((0.5 + (atan2(vec_dot(i->normal, x),
	// vec_dot(i->normal, cross(cy.norm, x))) * 0.159159)) * r * 6, cy.d, cy.color) :
	// cy.color;
	return (1);
}
