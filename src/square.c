/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:52:24 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 19:26:00 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int		square_hit(t_square sq, t_params params)
{
	double	a;
	double	b;
	double	t1;
	double	t2;
	t_vec	d;

	a = vec_dot(vec_sub(params.ray.o, sq.vec), sq.norm);
	b = vec_dot(params.ray.d, sq.norm);
	if (fabs(b) < 1e-6 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	t1 = -a / b;
	d = vec_sub(vec_add(vec_mult(params.ray.d, t1), params.ray.o), sq.vec);
	t2 = sq.size / 2;
	if (fabs(d.x) > t2 || fabs(d.y) > t2 || fabs(d.z) > t2)
		return (0);
	if (t1 > params.min && t1 < params.max)
	{
		params.hit->t = t1;
		params.hit->p = vec_at(params.ray, params.hit->t);
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
