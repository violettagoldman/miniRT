#include "../rt.h"

int		check_file_name(char *file)
{
	while (*file != '.')
		file++;
	if (ft_strcmp(file, ".rt"))
	{
		error("Error\nFile name error");
		return (0);
	}
	return (1);
}
