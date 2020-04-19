#ifndef CYLINDER_H
# define CYLINDER_H
# include "vec.h"
# include "color.h"

typedef struct		s_cylinder
{
	t_vec	vec;
	t_vec	norm;
	double	d;
	double	h;
	t_color	col;
}					t_cylinder;

#endif
