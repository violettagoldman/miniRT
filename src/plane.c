/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:51:14 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 12:18:54 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int	plane_hit(t_plane p, double min, double max, t_hit *hit, t_ray ray)
{
	double	t;
	double	denom;
	t_vec	tmp;
	
	p.norm = vec_mult(p.norm, -1);
	denom = vec_dot(p.norm, ray.d);
	if (denom > 1e-6)
	{
		tmp = vec_sub(p.vec, ray.o);
		t = vec_dot(tmp, p.norm) / denom;
		if (t >= min && t <= max)
		{
			hit->t = t;
			hit->p = vec_at(ray, hit->t);
			return (t >= 0);
		}
	}
	return (0);
}
