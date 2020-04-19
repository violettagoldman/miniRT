#ifndef OBJ_H
# define OBJ_H
# include "vec.h"
# include "sphere.h"
# include "plane.h"
# include "square.h"
# include "cylinder.h"
# include "square.h"
# include "triangle.h"

union			shape
{
	t_sphere	sp;
	t_plane		pl;
	t_square	sq;
	t_cylinder	cy;
	t_triangle	tr;
};

typedef struct		s_obj
{
	int				type;
	union shape		sh;
	struct s_obj	*next;
}					t_obj;

#endif
