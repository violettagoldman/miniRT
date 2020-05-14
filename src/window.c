/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:53:32 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 13:15:55 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int		key_pressed(int key, t_rt *rt)
{
	t_camera	*c;

	printf("%d\n", key);
	c = rt->current_cam;
	if (key == (LINUX ? 65362 : 126))
		c->vec = vec_add(c->vec, vec_mult(vec_cross(c->vertical, c->horizontal), 0.08));
	if (key == (LINUX ? 65364 : 125))
		c->vec = vec_add(c->vec, vec_mult(vec_cross(c->vertical, c->horizontal), -0.08));
	if (key == (LINUX ? 65363 : 124))
		c->vec = vec_add(c->vec, vec_mult(c->horizontal, 0.08));
	if (key == (LINUX ? 65361 : 123))
		c->vec = vec_add(c->vec, vec_mult(c->horizontal, -0.08));
	if (key == (LINUX ? 65307 : 53))
		program_exited(rt);
	if (key == (LINUX ? 97 : 0))
		c->norm = rotation(c->norm, vec_new(0, -1, 0));
	if (key == (LINUX ? 100 : 2))
		c->norm = rotation(c->norm, vec_new(0, 1, 0));
	if (key == (LINUX ? 120 : 7))
	{
		if (c->nb - 1 <= 0)
			camera_switch(rt, 0);
		else
			camera_switch(rt, c->nb - 1);
	}
	if (key == (LINUX ? 99 : 8))
	{
		if (c->nb + 1 >= rt->nb_cam)
			camera_switch(rt, 0);
		else
			camera_switch(rt, c->nb + 1);
	}

	return (0);
}

int		mouse_rotation(int b, int x, int y, t_rt *rt)
{
	t_camera *c;

	(void)y;
	c = rt->current_cam;
	if (b == 1)
	{
		if (x > rt->window.w/2)
		{
			if (c->nb + 1 >= rt->nb_cam)
				camera_switch(rt, 0);
			else
				camera_switch(rt, c->nb + 1);
		}
		else
		{
			if (c->nb - 1 <= 0)
				camera_switch(rt, 0);
			else
				camera_switch(rt, c->nb - 1);
		}
	}
	if (b == 4)
		c->norm = rotation(c->norm, vec_new(0, -1, 0));
	if (b == 5)
		c->norm = rotation(c->norm, vec_new(0, 1, 0));
	return (0);
}


int		program_exited(void *rt)
{
	free_rt(rt);
	exit(0);
}
