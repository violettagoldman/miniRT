/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:51:22 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 15:19:47 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

t_ray	ray_get(t_camera c, double u, double v)
{
	return (ray_new(c.origin, vec_norm(vec_sub(vec_add(c.lower_left_corner,
				vec_add(vec_mult(c.horizontal, u), vec_mult(c.vertical, v))),
				c.origin))));
}

t_ray	ray_new(t_vec o, t_vec d)
{
	t_ray ray;

	ray.o = o;
	ray.d = d;
	return (ray);
}
