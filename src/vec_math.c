/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:53:05 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 16:57:24 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

t_vec		vec_norm(t_vec vec)
{
	double mg;

	mg = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (vec_div(vec, mg));
}

t_vec		vec_new(double x, double y, double z)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec		vec_cross(t_vec a, t_vec b)
{
	return (vec_new(a.y * b.z - a.z * b.y, -(a.z * b.x - a.x * b.z), a.x * b.y -
			a.y * b.x));
}

t_vec		vec_cross2(t_vec a, t_vec b)
{
	return (vec_new(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y -
			a.y * b.x));
}

double		vec_len(t_vec vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}
