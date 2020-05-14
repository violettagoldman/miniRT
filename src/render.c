/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:52:00 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 20:26:34 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

t_vec	ray_color(t_rt *rt, t_ray ray)
{
	t_rc	rc;

	rc.n = vec_new(0, 0, 1);
	rc.t = intersect(rt, &(rc.hit), ray, &(rc.obj));
	rc.tmp = rt->l;
	if (rc.t > 0.0)
	{
		rc.n = get_norm(rc.obj, rc.hit);
		rc.col = vec_mult_vec(color_get(rc.obj),
				vec_mult(color_to_vec(rt->amb.col), rt->amb.range));
		while (rc.tmp)
		{
			ray_color_helper(&rc);
			if (intersect(rt, &(rc.a), rc.shadow, &(rc.obj)) &&
			rc.a.t + 1e-6 < vec_len(vec_sub(rc.hit.p, rc.tmp->vec)))
				rc.light_sum = vec_new(0, 0, 0);
			rc.col = vec_clamp(vec_add(rc.col, rc.light_sum));
			rc.tmp = rc.tmp->next;
		}
		return (rc.col);
	}
	rc.unit_direction = unit_vector(ray.d);
	rc.t = 0.5 * (rc.unit_direction.y + 1.0);
	return (vec_add(vec_mult(vec_new(1.0, 1.0, 1.0), 1.0 - rc.t),
			vec_mult(vec_new(0.5, 0.7, 1.0), rc.t)));
}

void	*render(void *arg)
{
	t_ren		ren;

	ren.rt = (t_rt *)((t_args *)arg)->rt;
	ren.j = ren.rt->window.h;
	ren.cam = *(ren.rt->current_cam);
	while (ren.j > 0 && (ren.i = ((t_args *)arg)->x) >= 0)
	{
		while (ren.i < ren.rt->window.w)
		{
			ren.color = vec_new(0, 0, 0);
			ren.u = (double)ren.i / ren.rt->window.w;
			ren.v = (double)ren.j / ren.rt->window.h;
			ren.r = ray_get(ren.cam, ren.u, ren.v);
			ren.color = vec_add(ren.color, ray_color(ren.rt, ren.r));
			put_pixel(ren.rt->window, ren.i, ren.j, ren.color);
			ren.i += THREADS;
		}
		--(ren.j);
	}
	return (NULL);
}

double	intersect(t_rt *rt, t_hit *hit, t_ray ray, t_obj *obj)
{
	t_params	par;
	t_hit		hit_tmp;
	double		inter;
	t_obj		*tmp;

	inter = 0;
	par.min = 0;
	par.max = INFINITY;
	tmp = rt->obj;
	while (tmp)
	{
		if (hit_get(tmp, par, &hit_tmp, ray))
		{
			*obj = *tmp;
			inter = 1;
			par.max = hit_tmp.t;
			*hit = hit_tmp;
		}
		tmp = tmp->next;
	}
	return (inter);
}

double	hit_get(t_obj *obj, t_params par, t_hit *hit, t_ray ray)
{
	int	type;

	type = obj->type;
	par.hit = hit;
	par.ray = ray;
	if (type == 0)
		return (hit_sphere(obj->sh.sp, par));
	else if (type == 1)
		return (plane_hit(obj->sh.pl, par));
	else if (type == 2)
		return (square_hit(obj->sh.sq, par));
	else if (type == 3)
		return (cylinder_hit(obj->sh.cy, par));
	else if (type == 4)
		return (triangle_hit(obj->sh.tr, par));
	return (0);
}
