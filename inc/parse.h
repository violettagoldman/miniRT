#ifndef PARSE_H
# define PARSE_H
# include <stdio.h>
# include <fcntl.h>
# include "../src/get_next_line/get_next_line.h"
# include "rt.h"

int			parse(char *file, t_rt *rt);
double		ft_atof(char **s);
int			ft_atoi(char **str);
void		add_res(char *line, t_rt *rt);
void		init(t_rt *rt);
void		add_amb(char *line, t_rt *rt);
int			check_bounds_vec(t_vec vec, int min, int max);
int			check_bounds_col(t_color col);
void		error(char *s);
void		add_camera(char *line, t_rt *rt);
void		add_light(char *line, t_rt *rt);
void		add_sphere(char *line, t_obj *obj);
void		add_plane(char *line, t_obj *obj);
void		add_square(char *line, t_obj *obj);
void		add_cylinder(char *line, t_obj *obj);
void		add_triangle(char *line, t_obj *obj);
void		send_to_obj(char *line, t_rt *rt);
void		check_parse(t_rt rt);
int			spaces(char c);
#endif
