#include "../rt.h"

t_vec ray_color(t_rt *rt, t_ray ray)
{
    t_hit hit;
	t_obj obj;
	t_vec n = vec_new(0, 0, 1);
	t_light *tmp;
	t_vec col;
	double t = intersect(rt, &hit, ray, &obj);
	tmp = rt->l;
	if (t > 0.0)
    {
		n = get_norm(obj, hit);
		col = vec_mult_vec(color_get(obj), vec_mult(color_to_vec(rt->amb.col), rt->amb.range));
		t_vec light_sum;
		while (tmp)
		{
			double dt = vec_dot(vec_norm(vec_sub(tmp->vec, hit.p)), vec_norm(n));
			light_sum = vec_mult(color_to_vec(tmp->col), dt * tmp->bright);
			t_ray shadow;
			shadow.o = tmp->vec;
			shadow.d = vec_norm(vec_sub(hit.p, tmp->vec));
			t_hit a;
			if (intersect(rt, &a, shadow, &obj) &&
			a.t + 1e-6 < vec_len(vec_sub(hit.p, tmp->vec)))
			{
				light_sum = vec_new(0, 0, 0);
			}
			col = vec_clamp(vec_add(col, light_sum));
			tmp = tmp->next;
		}
		return (col);
	}
    t_vec unit_direction = unit_vector(ray.d);
    t = 0.5 * (unit_direction.y + 1.0);
    return vec_add(vec_mult(vec_new(1.0, 1.0, 1.0), 1.0 - t), vec_mult(vec_new(0.5, 0.7, 1.0), t));
}

void *render(void *arg)
{
	t_rt		*rt;
	t_camera	cam;
	int			i;
	int			j;

	rt = (t_rt *)((t_args *)arg)->rt;
    j = rt->window.h;
	cam = *(rt->current_cam);

	while (j > 0 && (i = ((t_args *)arg)->x) >= 0)
	{
		while (i < rt->window.w )
		{
			t_vec color = vec_new(0, 0, 0);
			double u = (double)i / rt->window.w;
			double v = (double)j / rt->window.h;
			t_ray r = ray_get(cam, u, v);
			color = vec_add(color, ray_color(rt, r));
			put_pixel(rt->window, i, j, color);
			i += THREADS;
		}
		--j;
	}
	return (NULL);
}

double	intersect(t_rt *rt, t_hit *hit, t_ray ray, t_obj *obj)
{
	double	min;
	double	max;
	t_hit	hit_tmp;
	double	inter;
	t_obj	*tmp;

	inter = 0;
	min = 0;
	max = INFINITY;
	tmp = rt->obj;
	while (tmp)
	{
		if (hit_get(tmp, min, max, &hit_tmp, ray))
		{
			*obj = *tmp;
			inter = 1;
			max = hit_tmp.t;
			*hit = hit_tmp;
		}
		tmp = tmp->next;
	}
	return (inter);
}

double	hit_get(t_obj *obj, double min, double closest, t_hit *hit, t_ray ray)
{
	int type;

	//printf("TYPE = %d\n", obj->type);
	type = obj->type;
	if (type == 0)
		 return (hit_sphere(obj->sh.sp, min, closest, hit, ray));
	else if (type == 1)
		 return (plane_hit(obj->sh.pl, min, closest, hit, ray));
	else if (type == 2)
		return (square_hit(obj->sh.sq, min, closest, hit, ray));
	else if (type == 3)
		 return (cylinder_hit(obj->sh.cy, min, closest, hit, ray));
	else if (type == 4)
		return  (triangle_hit(obj->sh.tr, min, closest, hit, ray));
	return (0);
}
