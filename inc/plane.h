#ifndef PLANE_H
# define PLANE_H
# include "vec.h"
# include "color.h"

typedef struct		s_plane
{
	t_vec	vec;
	t_vec	norm;
	t_color	col;
}					t_plane;

#endif
