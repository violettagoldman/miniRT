#include "../inc/parse.h"

void	add_square(char *line, t_obj *obj)
{
	line += 2;
	obj->sh.sq.vec.x = ft_atof(&line);
	obj->sh.sq.vec.y = ft_atof(&line);
	obj->sh.sq.vec.z = ft_atof(&line);
	obj->sh.sq.norm.x = ft_atof(&line);
	obj->sh.sq.norm.y = ft_atof(&line);
	obj->sh.sq.norm.z = ft_atof(&line);
	obj->sh.sq.size = ft_atof(&line);
	obj->sh.sq.col.r = ft_atoi(&line);
	obj->sh.sq.col.g = ft_atoi(&line);
	obj->sh.sq.col.b = ft_atoi(&line);
	obj->next = NULL;
	obj->type = 2;
	if (!check_bounds_col(obj->sh.sq.col) && !check_bounds_vec(obj->sh.sq.norm,
		-1, 1))
		error("Error\nsq: values are out of bounds");
}

void	add_cylinder(char *line, t_obj *obj)
{
	line += 2;
	obj->sh.cy.vec.x = ft_atof(&line);
	obj->sh.cy.vec.y = ft_atof(&line);
	obj->sh.cy.vec.z = ft_atof(&line);
	obj->sh.cy.norm.x = ft_atof(&line);
	obj->sh.cy.norm.y = ft_atof(&line);
	obj->sh.cy.norm.z = ft_atof(&line);
	obj->sh.cy.d = ft_atof(&line);
	obj->sh.cy.h = ft_atof(&line);
	obj->sh.cy.col.r = ft_atoi(&line);
	obj->sh.cy.col.g = ft_atoi(&line);
	obj->sh.cy.col.b = ft_atoi(&line);
	obj->next = NULL;
	obj->type = 3;
	if (!check_bounds_col(obj->sh.cy.col) && !check_bounds_vec(obj->sh.cy.norm,
		-1, 1))
		error("Error\ncy: values are out of bounds");
}

void	add_triangle(char *line, t_obj *obj)
{
	line += 2;
	obj->sh.tr.first.x = ft_atof(&line);
	obj->sh.tr.first.y = ft_atof(&line);
	obj->sh.tr.first.z = ft_atof(&line);
	obj->sh.tr.second.x = ft_atof(&line);
	obj->sh.tr.second.y = ft_atof(&line);
	obj->sh.tr.second.z = ft_atof(&line);
	obj->sh.tr.third.x = ft_atof(&line);
	obj->sh.tr.third.y = ft_atof(&line);
	obj->sh.tr.third.z = ft_atof(&line);
	obj->sh.tr.col.r = ft_atoi(&line);
	obj->sh.tr.col.g = ft_atoi(&line);
	obj->sh.tr.col.b = ft_atoi(&line);
	obj->next = NULL;
	obj->type = 4;
	if (!check_bounds_col(obj->sh.tr.col))
		error("Error\ntr: values are out of bounds");
}
