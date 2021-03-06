/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:53:21 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/18 14:34:12 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

t_vec	vec_at(t_ray ray, double t)
{
	return (vec_add(ray.o, vec_mult(ray.d, t)));
}

void	vec_print(t_vec vec)
{
	(void)vec;
}

t_vec	vec_mult_vec(t_vec a, t_vec b)
{
	t_vec	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

t_vec	unit_vector(t_vec vec)
{
	return (vec_div(vec, vec_len(vec)));
}
