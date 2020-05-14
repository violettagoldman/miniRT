#include "../rt.h"

int		main(int argc, char **argv)
{
	t_rt rt;

	rt.l = NULL;
	rt.obj = NULL;
	rt.c = NULL;
	rt.save = 0;
	if (argc == 1)
		error("Error\nToo few arguments", &rt);
	else if (argc == 2 || argc == 3)
	{
		init(&rt);
		parse(argv[1], &rt);
		camera_init(&rt);
		rt.current_cam = rt.c;
		check_parse(rt);
		if (argc == 3 && !ft_strcmp(argv[2], "--save"))
		{
			rt.save = 1;
		}
		window_init(&rt);
	}
	else
		error("Error\nToo many arguments", &rt);
	return (0);
}
