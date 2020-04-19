#include "../inc/parse.h"

void	add_light(char *line, t_rt *rt)
{
	t_light	*l;

	if (!(l = (t_light *)malloc(sizeof(t_light))))
		error("Error\nc: malloc");
	line++;
	l->vec.x = ft_atof(&line);
	l->vec.y = ft_atof(&line);
	l->vec.z = ft_atof(&line);
	l->bright = ft_atof(&line);
	l->col.r = ft_atoi(&line);
	l->col.g = ft_atoi(&line);
	l->col.b = ft_atoi(&line);
	l->next = NULL;
	if (!check_bounds_col(l->col) || l->bright < 0 || l->bright > 1)
		error("Error\nl: values are out of bounds");
	if (!rt->l)
		rt->l = l;
	else
	{
		l->next = rt->l;
		rt->l = l;
	}
}

void	add_sphere(char *line, t_obj *obj)
{
	line += 2;
	obj->sh.sp.c.x = ft_atof(&line);
	obj->sh.sp.c.y = ft_atof(&line);
	obj->sh.sp.c.z = ft_atof(&line);
	obj->sh.sp.r = ft_atof(&line) / 2;
	obj->sh.sp.col.r = ft_atoi(&line);
	obj->sh.sp.col.g = ft_atoi(&line);
	obj->sh.sp.col.b = ft_atoi(&line);
	obj->next = NULL;
	obj->type = 0;
	if (!check_bounds_col(obj->sh.sp.col))
		error("Error\nsp: values are out of bounds");
}

void	add_plane(char *line, t_obj *obj)
{
	line += 2;
	obj->sh.pl.vec.x = ft_atof(&line);
	obj->sh.pl.vec.y = ft_atof(&line);
	obj->sh.pl.vec.z = ft_atof(&line);
	obj->sh.pl.norm.x = ft_atof(&line);
	obj->sh.pl.norm.y = ft_atof(&line);
	obj->sh.pl.norm.z = ft_atof(&line);
	obj->sh.pl.col.r = ft_atoi(&line);
	obj->sh.pl.col.g = ft_atoi(&line);
	obj->sh.pl.col.b = ft_atoi(&line);
	obj->next = NULL;
	obj->type = 1;
	if (!check_bounds_col(obj->sh.pl.col) && !check_bounds_vec(obj->sh.pl.norm,
		-1, 1))
		error("Error\npl: values are out of bounds");
}

int		check_bounds_col(t_color col)
{
	int min;
	int max;

	min = 0;
	max = 255;
	if (col.r < min || col.r > max || col.g < min || col.g > max
		|| col.b < min|| col.b > max)
		return (0);
	return (1);
}

void	error(char *s)
{
	perror(s);
	exit(-1);
}
