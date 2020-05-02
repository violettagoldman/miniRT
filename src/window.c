#include "../rt.h"

int	key_pressed(int key, t_rt *rt)
{
	if (key == 126)
		rt->c->vec.z -= 0.01;
	if (key == 125)
		rt->c->vec.z += 0.01 ;
	if (key == 124)
		rt->c->vec.x -= 0.01;
	if (key == 123)
		rt->c->vec.x += 0.01;

	(void)rt;
	printf("%d\n", key);
	return (0);
}

int	program_exited(void *rt)
{
	(void)rt;
	//stop_game((t_game *)game);
	exit(0);
	//return(0);
}
