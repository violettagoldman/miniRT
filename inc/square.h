#ifndef SQUARE_H
# define SQUARE_H
# include "vec.h"
# include "color.h"

typedef struct		s_square
{
	t_vec	vec;
	t_vec	norm;
	double	size;
	t_color	col;
}					t_square;

#endif
