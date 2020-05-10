#include "../rt.h"

int		key_pressed(int key, t_rt *rt)
{
	if (key == 126)
		rt->c->vec = vec_add(rt->c->vec, vec_mult(vec_cross(rt->c->vertical, rt->c->horizontal), 0.08));
	if (key == 125)
		rt->c->vec = vec_add(rt->c->vec, vec_mult(vec_cross(rt->c->vertical, rt->c->horizontal), -0.08));
	if (key == 124)
		rt->c->vec = vec_add(rt->c->vec, vec_mult(rt->c->horizontal, 0.08));
	if (key == 123)
		rt->c->vec = vec_add(rt->c->vec, vec_mult(rt->c->horizontal, -0.08));
	if (key == 53)
		program_exited(rt);
	if (key == 0)
		rt->c->norm = rotation(rt->c->norm, vec_new(0, -2, 0));
	if (key == 2)
		rt->c->norm = rotation(rt->c->norm, vec_new(0, 2, 0));
	return (0);
}

int		program_exited(void *rt)
{
	(void)rt;
	//stop_game((t_game *)game);
	exit(0);
	//return(0);
}
