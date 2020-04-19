#ifndef SPHERE_H
# define SPHERE_H
# include "vec.h"
# include "color.h"

typedef struct		s_sphere
{
	t_vec			c;
	double			r;
	t_color			col;
}					t_sphere;

#endif
