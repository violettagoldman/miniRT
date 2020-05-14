/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:52:35 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 19:33:14 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int		triangle_hit(t_triangle tr, t_params params)
{
	t_th	th;

	th.e1 = vec_sub(tr.second, tr.first);
	th.e2 = vec_sub(tr.third, tr.first);
	th.h = vec_cross2(params.ray.d, th.e2);
	th.a = vec_dot(th.e1, th.h);
	if (fabs(th.a) < 1e-6)
		return (0);
	th.f = 1 / th.a;
	th.s = vec_sub(params.ray.o, tr.first);
	th.u = th.f * vec_dot(th.s, th.h);
	if (th.u < 0 || th.u > 1)
		return (0);
	th.q = vec_cross2(th.s, th.e1);
	th.v = th.f * vec_dot(params.ray.d, th.q);
	if (th.v < 0 || th.u + th.v > 1)
		return (0);
	th.t = th.f * vec_dot(th.e2, th.q);
	if (th.t < 1e-6)
		return (0);
	params.hit->t = th.t;
	params.hit->p = vec_at(params.ray, params.hit->t);
	return (th.t > params.min && th.t < params.max);
}

t_vec	triangle_norm(t_triangle tr)
{
	return (vec_norm(vec_cross2(vec_sub(tr.second, tr.first),
			vec_sub(tr.third, tr.first))));
}
