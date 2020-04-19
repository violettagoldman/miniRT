#ifndef RT_H
# define RT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "window.h"
# include "camera.h"
# include "light.h"
# include "obj.h"

typedef struct		s_res
{
	int x;
	int y;
}					t_res;

typedef struct		s_amb
{
	double	range;
	t_color	col;
}					t_amb;

typedef struct		s_rt
{
	t_res		res;
	t_amb		amb;
	t_camera	*c;
	t_light		*l;
	t_obj		*obj;
	t_window	window;
}					t_rt;

#endif
