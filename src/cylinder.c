/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:49:10 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 16:59:37 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

t_vec			cylinder_norm(t_cylinder cy, t_vec p)
{
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
		return (t1);
	if (t2 > 1e-6 && fabs(l2) <= cy.h)
		return (t2);
	return (-1);
}

static double	sqr(double x)
{
	return (x * x);
}

int				cylinder_hit(t_cylinder cy, t_params par)
{
	t_vec		x;
	double		a;
	double		b;
	double		d;
	double		r;

	r = cy.d / 2;
	x = vec_sub(par.ray.o, cy.vec);
	a = vec_dot(par.ray.d, par.ray.d) - sqr(vec_dot(par.ray.d, cy.norm));
	b = 2 * (vec_dot(par.ray.d, x) - vec_dot(par.ray.d, cy.norm) *
		vec_dot(x, cy.norm));
	d = vec_dot(x, x) - sqr(vec_dot(x, cy.norm)) - r * r;
	d = b * b - 4 * a * d;
	d = (fabs(d) < 1e-6) ? 0 :
	get_t((-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a), cy, par.ray);
	if (!(d > par.min && d < par.max))
		return (0);
	par.hit->t = d;
	par.hit->p = vec_add(par.ray.o, vec_mult(par.ray.d, d));
	return (1);
}
