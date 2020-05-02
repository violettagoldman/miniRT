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
      t_sphere light = sphere_new(vec_new(0, 0, 10), 10, color_new(10, 0, 255));
      t_vec pi = vec_add(ray.o, vec_mult(ray.d, hit.t));
      t_vec l = vec_sub(light.c, pi);
		if (obj.type == 0)
			n = sphere_norm(obj.sh.sp, pi);
		//n = sphere_norm(s, pi);
      double dt = vec_dot(vec_norm(l), vec_norm(n));
      // addition de amb light
      t_vec pix_col = vec_mult(
		vec_add(vec_new(122.0 / 255 + 0.2, 0.0 + 0.2, 200.0 / 255 + 0.2),
			vec_mult(vec_new(1.0, 1.0, 1.0), dt)), 0.5);
      return (pix_col);
      //return (vec_mult(vec_add(hit.norm, new_vec(1, 1, 1)), 0.5));
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
		if (tmp->type == 0)
		{
			if (hit_sphere(tmp->sh.sp, min, closest, &hit_tmp, ray))
			{
				*obj = *tmp;
				inter = 1;
				closest = hit_tmp.t;
				*hit = hit_tmp;
			}
		}
		tmp = tmp->next;
	}
	return (inter);
}
