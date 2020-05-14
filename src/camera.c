/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:48:54 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 17:17:51 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

void	camera_init_helper(t_rt *rt, t_pc *pc, t_camera *tmp)
{
	tmp->from = tmp->vec;
	tmp->up = vec_new(0, 1, 0);
	tmp->at = vec_add(tmp->vec, tmp->norm);
	tmp->aspect = (double)rt->window.w / rt->window.h;
	pc->half_h = tan(degrees_to_radians(tmp->fov) / 2);
	pc->half_w = -tmp->aspect * pc->half_h;
	pc->w = unit_vector(vec_sub(tmp->from, tmp->at));
	pc->u = unit_vector(vec_cross(tmp->up, pc->w));
}

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
		tmp->nb = i;
		camera_init_helper(rt, &pc, tmp);
		pc.v = vec_cross(pc.w, pc.u);
		tmp->origin = tmp->from;
		tmp->lower_left_corner = vec_sub(tmp->origin,
				vec_mult(pc.u, pc.half_w));
		tmp->lower_left_corner = vec_sub(tmp->lower_left_corner,
			vec_mult(pc.v, pc.half_h));
		tmp->lower_left_corner = vec_sub(tmp->lower_left_corner, pc.w);
		tmp->horizontal = vec_mult(pc.u, 2 * pc.half_w);
		tmp->vertical = vec_mult(pc.v, 2 * pc.half_h);
		tmp = tmp->next;
		i++;
	}
	rt->nb_cam = i;
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
