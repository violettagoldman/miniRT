#include "../rt.h"

int		key_pressed(int key, t_rt *rt)
{
	t_camera	*c;

	c = rt->current_cam;
	if (key == 126)
		c->vec = vec_add(c->vec, vec_mult(vec_cross(c->vertical, c->horizontal), 0.08));
	if (key == 125)
		c->vec = vec_add(c->vec, vec_mult(vec_cross(c->vertical, c->horizontal), -0.08));
	if (key == 124)
		c->vec = vec_add(c->vec, vec_mult(c->horizontal, 0.08));
	if (key == 123)
		c->vec = vec_add(c->vec, vec_mult(c->horizontal, -0.08));
	if (key == 53)
		program_exited(rt);
	if (key == 0)
		c->norm = rotation(c->norm, vec_new(0, -1, 0));
	if (key == 2)
		c->norm = rotation(c->norm, vec_new(0, 1, 0));
	if (key == 7)
	{
		if (c->nb - 1 <= 0)
			camera_switch(rt, 0);
		else
			camera_switch(rt, c->nb - 1);
	}
	if (key == 8)
	{
		if (c->nb + 1 >= rt->nb_cam)
			camera_switch(rt, 0);
		else
			camera_switch(rt, c->nb + 1);
	}

	return (0);
}


int		program_exited(void *rt)
{
	(void)rt;
	//stop_game((t_game *)game);
	exit(0);
	//return(0);
}
