#ifndef VEC_H
# define VEC_H
# include <stdlib.h>

typedef struct		s_vec
{
	double	x;
	double	y;
	double	z;
}					t_vec;

t_vec	vec_add(t_vec a, t_vec b);
t_vec	vec_sub(t_vec a, t_vec b);
t_vec	vec_mult(t_vec a, double i);
t_vec	vec_div(t_vec a, double i);
double	vec_dot(t_vec a, t_vec b);
t_vec	vec_norm(t_vec vec);
t_vec	vec_set(t_vec vec, double x, double y, double z);

#endif
