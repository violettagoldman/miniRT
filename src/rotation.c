/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:52:07 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 18:38:19 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

t_vec		rotation_x(t_vec vec, double x)
{
	t_vec	res;

	x = degrees_to_radians(x);
	res.x = vec.x;
	res.y = vec.y * cos(x) - vec.z * sin(x);
	res.z = vec.y * sin(x) + vec.z * cos(x);
	return (res);
}

t_vec		rotation_y(t_vec vec, double y)
{
	t_vec	res;

	y = degrees_to_radians(y);
	res.x = vec.x * cos(y) + vec.z * sin(y);
	res.y = vec.y;
	res.z = vec.x * -sin(y) + vec.z * cos(y);
	return (res);
}

t_vec		rotation_z(t_vec vec, double z)
{
	t_vec	res;

	z = degrees_to_radians(z);
	res.x = vec.x * cos(z) - vec.y * sin(z);
	res.y = vec.x * sin(z) + vec.y * cos(z);
	res.z = vec.z;
	return (res);
}

t_vec		rotation(t_vec vec, t_vec angle)
{
	t_vec res;

	res = rotation_x(vec, angle.x);
	res = rotation_y(res, angle.y);
	res = rotation_z(res, angle.z);
	return (res);
}
