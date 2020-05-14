/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:52:49 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 18:06:28 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int			ft_atoi(char **str, t_rt *rt)
{
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	while (**str == '\t' || **str == '\n' || **str == '\f' || **str == '\r' ||
			**str == ' ' || **str == '\v' || **str == ',')
		(*str)++;
	if (**str == '-')
	{
		sign *= -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	if (!(**str >= '0' && **str <= '9'))
		error("Error\nBadly formated file", rt);
	while (**str && **str >= '0' && **str <= '9')
	{
		res = (res * 10) + (**str - '0');
		(*str)++;
	}
	return (res * sign);
}

double		ft_atof(char **s, t_rt *rt)
{
	int		integer;
	int		sign;
	double	res;

	while (**s == '\t' || **s == '\n' || **s == '\f' || **s == '\r' ||
			**s == ' ' || **s == '\v' || **s == ',' || (sign = 1) == 2)
		(*s)++;
	if (**s == '-')
	{
		sign *= -1;
		(*s)++;
	}
	else if (**s == '+')
		(*s)++;
	integer = ft_atoi(s, rt);
	res = 0;
	if (*s && **s == '.')
	{
		(*s)++;
		res = (double)ft_atoi(s, rt);
	}
	while (res >= 1)
		res /= 10;
	res += integer;
	return (res * sign);
}

double		degrees_to_radians(double degrees)
{
	return (degrees * PI / 180);
}

t_hit		face_norm(t_hit hit, t_ray ray, t_vec normal)
{
	t_hit r;

	r.front = (vec_dot(ray.d, normal) < 0);
	r.norm = hit.front ? normal : vec_mult(normal, -1);
	r.t = hit.t;
	return (r);
}

double		ft_clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}
