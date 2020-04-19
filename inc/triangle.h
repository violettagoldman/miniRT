#ifndef TRIANGLE_H
# define TRIANGLE_H
# include "vec.h"
# include "color.h"

typedef struct		s_trianlge
{
	t_vec	first;
	t_vec	second;
	t_vec	third;
	t_color	col;
}					t_triangle;

#endif
