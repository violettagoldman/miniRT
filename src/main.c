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
		check_parse(rt);
		if (argc == 2)
			window_init(&rt);
		else if (argc == 3 && !ft_strcmp(argv[2], "--save"))
		{
			threads_init(&rt);
			//writebmp(rt.window.h, rt.window.w, rt.window.image_data);
		}
	}
	else
		error("Error\nToo many arguments");
    return (0);
}
