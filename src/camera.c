#include "../rt.h"
//Do we actually need origin, from and vec?

void	camera_init(t_rt *rt)
{
	t_camera	*tmp;
	double		half_h;
	double		half_w;
	t_vec		u;
	t_vec		v;
	t_vec		w;
	int			i;

	i = 0;
	tmp = rt->c;
	if (!tmp)
		return ;
	while (tmp)
	{
		tmp->nb = i;
		tmp->from = tmp->vec;
		tmp->up = vec_new(0, 1, 0);
		tmp->at = vec_add(tmp->vec, tmp->norm);
		tmp->aspect = (double)rt->window.w / rt->window.h;
		half_h = tan(degrees_to_radians(tmp->fov) / 2);
		half_w = -tmp->aspect * half_h;
		w = unit_vector(vec_sub(tmp->from, tmp->at));
		u = unit_vector(vec_cross(tmp->up, w));
		v = vec_cross(w, u);
		tmp->origin = tmp->from;
		//tmp->lower_left_corner = vec_sub(vec_sub(tmp->origin,
		//vec_mult(u, -half_w)), vec_sub(vec_mult(v, half_h), w));
		tmp->lower_left_corner = vec_sub(tmp->origin, vec_mult(u, half_w));
		tmp->lower_left_corner = vec_sub(tmp->lower_left_corner, vec_mult(v, half_h));
		tmp->lower_left_corner = vec_sub(tmp->lower_left_corner, w);
		tmp->horizontal = vec_mult(u, 2 * half_w);
		tmp->vertical = vec_mult(v, 2 * half_h);
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
