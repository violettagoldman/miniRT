#include "../rt.h"

t_vec ray_color(t_rt *rt, t_ray ray)
{
    //t_sphere s;
    t_hit hit;
	t_obj obj;
	(void)rt;
	t_vec n = vec_new(0, 0, 1);

    //s = sphere_new(vec_new(0, 0, 10), 1, color_new(0, 0, 255));
    //double t = hit_sphere(s, 0, INFINITY, &hit, ray);
	double t = intersect(rt, &hit, ray, &obj);
	if (t > 0.0)
    {
      t_light light = light_new(rt->l->vec, rt->l->bright, rt->l->col);
      t_vec pi = vec_add(ray.o, vec_mult(ray.d, hit.t));
	  //printf("%f\n", hit.t);
      t_vec l = vec_sub(light.vec, pi);
		if (obj.type == 0)
			n = sphere_norm(obj.sh.sp, pi);
		else if (obj.type == 1)
			n = vec_mult(obj.sh.pl.norm, -1);
		else if (obj.type == 2)
			n = vec_new(0, 0, 1);
		else if (obj.type == 3)
			n = vec_new(0, 0, 1);
		else if (obj.type == 4)
			n = vec_new(0, 0, 1);
		//n = sphere_norm(s, pi);
		double dt = vec_dot(vec_norm(l), vec_norm(n));
		// addition de amb light
		t_vec pix_col;
		if (obj.type == 0)
			pix_col = vec_mult(
			vec_add(color_to_vec(obj.sh.sp.col),
				vec_mult(color_to_vec(light.col), dt * light.bright)), rt->amb.range);
		if (obj.type == 1)
			pix_col = vec_mult(
			vec_add(color_to_vec(obj.sh.pl.col),
				vec_mult(color_to_vec(light.col), dt * light.bright)), rt->amb.range);
		if (obj.type == 2)
			pix_col = vec_mult(
			vec_add(color_to_vec(obj.sh.sq.col),
				vec_mult(color_to_vec(light.col), dt * light.bright)), rt->amb.range);
		t_ray shadow;
		double col_shadow = 1;
		shadow.o = light.vec;
		shadow.d = vec_norm(vec_sub(hit.p, light.vec));
		if (intersect(rt, &hit, shadow, &obj) &&
			hit.t + 1e-6 < vec_len(vec_sub(hit.p, light.vec)))
		{
			printf("HIT.T = %f, LEN = %f\n", hit.t, vec_len(vec_sub(hit.p, light.vec)));
			col_shadow = 0.2;
		}
		return (vec_clamp(vec_mult(pix_col, col_shadow)));
    }
    t_vec unit_direction = unit_vector(ray.d);
    t = 0.5 * (unit_direction.y + 1.0);
    return vec_add(vec_mult(vec_new(1.0, 1.0, 1.0), 1.0 - t), vec_mult(vec_new(0.5, 0.7, 1.0), t));
}

void render(t_rt *rt)
{
    int i;
    int j;
    int k;
    t_camera cam;

    j = rt->window.h;
	camera_init(rt);
    cam = *(rt->c);
	while (j > 0)
    {
        i = 0;
        while (i < rt->window.w)
        {
            k = 0;
            t_vec color = vec_new(0, 0, 0);
            //while (k < per_pix)
            //{
              double u = (double)i / rt->window.w;
              double v = (double)j / rt->window.h;
			  t_ray r = ray_get(cam, u, v);
              color = vec_add(color, ray_color(rt, r));
              ++k;
            //}
            put_pixel(rt->window, i, j, color);
            ++i;
        }
        --j;
    }
}

double	intersect(t_rt *rt, t_hit *hit, t_ray ray, t_obj *obj)
{
	double min;
	double max;
	t_hit hit_tmp;
	double		inter;
	double closest;
	t_obj *tmp;

	inter = 0;
	min = 0;
	max = INFINITY;
	closest = max;
	tmp = rt->obj;
	while (tmp)
	{
		if (hit_get(tmp, min, closest, &hit_tmp, ray))
		{
			*obj = *tmp;
			inter = 1;
			closest = hit_tmp.t;
			*hit = hit_tmp;
		}
		tmp = tmp->next;
	}
	return (inter);
}

double	hit_get(t_obj *obj, double min, double closest, t_hit *hit, t_ray ray)
{
	int type;

	type = obj->type;
	if (type == 0)
		 return (hit_sphere(obj->sh.sp, min, closest, hit, ray));
	else if (type == 1)
		 return (plane_hit(obj->sh.pl, min, closest, hit, ray));
	else if (type == 2)
		return (square_hit(obj->sh.sq, min, closest, hit, ray));
	else if (type == 3)
		return  0;//(hit_triangle(obj->sh.tr, min, closest, hit, ray));
	else if (type == 4)
		 return 0;//(hit_cylinder(obj->sh.cy, min, closest, hit, ray));
	return (0);
}
