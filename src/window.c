#include "../rt.h"

int		key_pressed(int key, t_rt *rt)
{
	if (key == 126)
		rt->c->vec.z += 0.08;
	if (key == 125)
		rt->c->vec.z -= 0.08;
	if (key == 124)
		rt->c->vec.x += 0.08;
	if (key == 123)
		rt->c->vec.x -= 0.08;
	if (key == 53)
		program_exited(rt);

	return (0);
}

int		program_exited(void *rt)
{
	(void)rt;
	//stop_game((t_game *)game);
	exit(0);
	//return(0);
}
