/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:48:54 by vgoldman          #+#    #+#             */
/*   Updated: 2020/06/02 17:51:00 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

void	camera_init(t_rt *rt)
{
	t_camera	*tmp;
	t_pc		pc;
	int			i;

	i = 0;
	tmp = rt->c;
	if (!tmp)
		return ;
	while (tmp)
	{
		camera_init_helper(tmp, &pc, i, rt);
		pc.vup = vec_new(0, -1, 0);
		pc.w = vec_norm(vec_sub(tmp->from, tmp->at));
		pc.u = vec_norm(vec_cross(pc.vup, pc.w));
		t_vec v = vec_cross(pc.w, pc.u);
		tmp->horizontal = (vec_mult(pc.u, pc.viewport_width));
		tmp->vertical = (vec_mult(v, pc.viewport_height));
		tmp->vertical = vec_mult_vec(tmp->vertical, vec_new(0, -1, 0));
		tmp->lower_left_corner = vec_sub(tmp->origin, vec_mult(tmp->horizontal, 0.5));
		tmp->lower_left_corner = vec_sub(tmp->lower_left_corner, vec_mult(tmp->vertical, 0.5));
		tmp->lower_left_corner = vec_sub(tmp->lower_left_corner, pc.w);
		tmp = tmp->next;
		i++;
	}
	rt->nb_cam = i;
}

void	camera_init_helper(t_camera *tmp, t_pc *pc, int i, t_rt *rt)
{
	tmp->from = tmp->vec;
	tmp->origin = tmp->vec;
	tmp->norm = vec_norm(tmp->norm);
	tmp->at = vec_add(tmp->vec, tmp->norm);
	tmp->nb = i;
	pc->aspect_ratio = (double)rt->window.w / rt->window.h;
	pc->theta = degrees_to_radians(tmp->fov);
	pc->h = tan(pc->theta / 2);
	pc->viewport_height = 2 * pc->h;
	pc->viewport_width = pc->aspect_ratio * pc->viewport_height;
}

void	camera_switch(t_rt *rt, int nb)
{
	t_camera *tmp;

	tmp = rt->c;
	while (tmp)
	{
		if (tmp->nb == nb)
		{
			rt->current_cam = tmp;
			return ;
		}
		else
			tmp = tmp->next;
	}
}
