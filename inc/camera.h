#ifndef CAMERA_H
# define CAMERA_H
# include "vec.h"

typedef struct		s_camera
{
	t_vec				vec;
	t_vec				norm;
	double				fov;
	struct s_camera		*next;
}					t_camera;

#endif
