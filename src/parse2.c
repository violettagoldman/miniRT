#include "../rt.h"

int		check_file_name(char *file, t_rt *rt)
{
	while (*file != '.')
		file++;
	if (ft_strcmp(file, ".rt"))
	{
		error("Error\nFile name error", rt);
		return (0);
	}
	return (1);
}
