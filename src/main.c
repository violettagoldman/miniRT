#include "../rt.h"

int main(int argc, char **argv)
{
	t_rt rt;

	if (argc == 1)
		error("Error\nToo few arguments");
	else if (argc == 2 || argc == 3)
	{
		init(&rt);
		parse(argv[1], &rt);
		camera_init(&rt);
		rt.current_cam = rt.c;
		check_parse(rt);
		window_init(&rt);
		/*if (argc == 3 && !ft_strcmp(argv[2], "--save"))
		{
			
		}*/
	}
	else
		error("Error\nToo many arguments");
    return (0);
}
