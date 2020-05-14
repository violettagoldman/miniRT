/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:52:15 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 19:07:57 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

t_sphere	*create_sphere(t_vec c, double r, t_color color)
{
	t_sphere *sphere;

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sphere->c = c;
	sphere->r = r;
	sphere->col = color;
	return (sphere);
}

double		hit_sphere(t_sphere s, t_params params)
{
	t_hs	hs;

	hs.oc = vec_sub(params.ray.o, s.c);
	hs.a = vec_dot(params.ray.d, params.ray.d);
	hs.half_b = vec_dot(hs.oc, params.ray.d);
	hs.c = vec_dot(hs.oc, hs.oc) - s.r * s.r;
	hs.discriminant = hs.half_b * hs.half_b - hs.a * hs.c;
	if (hs.discriminant > 0)
	{
		hs.root = sqrt(hs.discriminant);
		hs.temp = (-hs.half_b - hs.root) / hs.a;
		if (hs.temp < params.max && hs.temp > params.min)
		{
			hit_sphere_helper(s, &params, &hs);
			return (1);
		}
		hs.temp = (-hs.half_b + hs.root) / hs.a;
		if (hs.temp < params.max && hs.temp > params.min)
		{
			hit_sphere_helper(s, &params, &hs);
			return (1);
		}
	}
	return (0);
}

t_sphere	sphere_new(t_vec c, double r, t_color col)
{
	t_sphere s;

	s.c = c;
	s.r = r;
	s.col = col;
	return (s);
}

t_vec		sphere_norm(t_sphere s, t_vec pi)
{
	t_vec res;

	res = vec_sub(pi, s.c);
	vec_div(res, s.r);
	return (res);
}
