/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 19:22:04 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/28 16:35:57 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

void	hit_sphere_helper(t_sphere s, t_params *params, t_hs *hs)
{
	hs->norm = vec_div(vec_sub(params->hit->p, s.c), s.r);
	*(params->hit) = face_norm(*(params->hit), params->ray, hs->norm);
	params->hit->t = hs->temp;
	params->hit->p = vec_at(params->ray, params->hit->t);
}

void	ray_color_helper(t_rc *rc)
{
	rc->dt = vec_dot(vec_norm(vec_sub(rc->tmp->vec, rc->hit.p)),
			vec_norm(rc->n));
	rc->light_sum = vec_mult(color_to_vec(rc->tmp->col),
		rc->dt * rc->tmp->bright);
rc->shadow.o = rc->tmp->vec;
	rc->shadow.d = vec_norm(vec_sub(rc->hit.p, rc->tmp->vec));
}
