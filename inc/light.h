#ifndef LIGHT_H
# define LIGHT_H
# include "vec.h"
# include "color.h"

typedef struct		s_light
{
	t_vec			vec;
	double			bright;
	t_color			col;
	struct s_light	*next;
}					t_light;

#endif
