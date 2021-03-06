/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:48:36 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 22:02:10 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

void	add_res(char *line, t_rt *rt)
{
	int x;
	int y;

	line++;
	x = ft_atoi(&line, rt);
	y = ft_atoi(&line, rt);
	if (x <= 0 || y <= 0 || rt->res.x != -1 || rt->res.y != -1)
		error("Error\nR: already exists or values are out of bounds", rt);
	rt->res.x = x;
	rt->res.y = y;
	rt->window.w = x;
	rt->window.h = y;
}

void	add_amb(char *line, t_rt *rt)
{
	t_color	col;
	double	amb;

	line++;
	amb = ft_atof(&line, rt);
	col.r = ft_atoi(&line, rt);
	col.g = ft_atoi(&line, rt);
	col.b = ft_atoi(&line, rt);
	if (!check_bounds_col(col) || amb < 0.0 || amb > 1.0
		|| rt->amb.range != -1)
		error("Error\nA: already exists or values are out of bounds", rt);
	rt->amb.range = amb;
	rt->amb.col.r = col.r;
	rt->amb.col.g = col.g;
	rt->amb.col.b = col.b;
}

void	add_camera(char *line, t_rt *rt)
{
	t_camera	*c;

	if (!(c = (t_camera *)malloc(sizeof(t_camera))))
		error("Error\nc: malloc", rt);
	line++;
	c->vec.x = ft_atof(&line, rt);
	c->vec.y = ft_atof(&line, rt);
	c->vec.z = ft_atof(&line, rt);
	c->norm.x = ft_atof(&line, rt);
	c->norm.y = ft_atof(&line, rt);
	c->norm.z = ft_atof(&line, rt);
	c->fov = ft_atof(&line, rt);
	c->next = NULL;
	if (!check_bounds_vec(c->norm, -1, 1) || c->fov < 0 || c->fov > 180)
		error("Error\nc: values are out of bounds", rt);
	if (rt->c)
		c->next = rt->c;
	rt->c = c;
}

void	init(t_rt *rt)
{
	rt->res.x = -1;
	rt->res.y = -1;
	rt->amb.range = -1;
	rt->obj = NULL;
	rt->c = NULL;
	rt->l = NULL;
	rt->window.w = -1;
	rt->window.h = -1;
}

int		check_bounds_vec(t_vec vec, int min, int max)
{
	if (vec.x < min || vec.x > max || vec.y < min || vec.y > max
		|| vec.z < min || vec.x > max)
		return (0);
	return (1);
}
