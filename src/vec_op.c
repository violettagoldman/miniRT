/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:53:13 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 11:53:15 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

t_vec	vec_add(t_vec a, t_vec b)
{
	t_vec	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vec	vec_sub(t_vec a, t_vec b)
{
	t_vec	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vec	vec_mult(t_vec a, double i)
{
	t_vec	res;

	res.x = a.x * i;
	res.y = a.y * i;
	res.z = a.z * i;
	return (res);
}

t_vec	vec_div(t_vec a, double i)
{
	t_vec	res;

	res.x = a.x / i;
	res.y = a.y / i;
	res.z = a.z / i;
	return (res);
}

double	vec_dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
