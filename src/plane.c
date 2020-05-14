/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:51:14 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 18:19:44 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int	plane_hit(t_plane p, t_params params)
{
	double	t;
	double	denom;
	t_vec	tmp;

	p.norm = vec_mult(p.norm, -1);
	denom = vec_dot(p.norm, params.ray.d);
	if (denom > 1e-6)
	{
		tmp = vec_sub(p.vec, params.ray.o);
		t = vec_dot(tmp, p.norm) / denom;
		if (t >= params.min && t <= params.max)
		{
			params.hit->t = t;
			params.hit->p = vec_at(params.ray, params.hit->t);
			return (t >= 0);
		}
	}
	return (0);
}
