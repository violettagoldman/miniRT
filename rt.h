/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:27:24 by vgoldman          #+#    #+#             */
/*   Updated: 2020/06/02 17:52:54 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include "./src/get_next_line/get_next_line.h"
# include "./minilibx_linux/mlx.h"
# ifndef __linux__
#  define LINUX 0
# else
#  define LINUX 1
# endif
# define PI 3.1415926535897932385
# define THREADS 8

typedef struct			s_vec
{
	double				x;
	double				y;
	double				z;
}						t_vec;

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_ray
{
	t_vec				o;
	t_vec				d;
}						t_ray;

typedef struct			s_plane
{
	t_vec				vec;
	t_vec				norm;
	t_color				col;
}						t_plane;

typedef struct			s_sphere
{
	t_vec				c;
	double				r;
	t_color				col;
}						t_sphere;

typedef struct			s_square
{
	t_vec				vec;
	t_vec				norm;
	double				size;
	t_color				col;
}						t_square;

typedef struct			s_triangle
{
	t_vec				first;
	t_vec				second;
	t_vec				third;
	t_color				col;
}						t_triangle;

typedef struct			s_cylinder
{
	t_vec				vec;
	t_vec				norm;
	double				d;
	double				h;
	t_color				col;
}						t_cylinder;

typedef struct			s_window
{
	int					w;
	int					h;
	void				*mlx;
	void				*window;
	void				*image;
	char				*image_data;
}						t_window;

typedef struct			s_hit
{
	t_vec				p;
	t_vec				norm;
	double				t;
	int					front;
}						t_hit;

typedef struct			s_light
{
	t_vec				vec;
	double				bright;
	t_color				col;
	struct s_light		*next;
}						t_light;

typedef struct			s_res
{
	int					x;
	int					y;
}						t_res;

typedef struct			s_amb
{
	double				range;
	t_color				col;
}						t_amb;

union					u_shape
{
	t_sphere			sp;
	t_plane				pl;
	t_square			sq;
	t_cylinder			cy;
	t_triangle			tr;
};

typedef struct			s_obj
{
	int					type;
	union u_shape		sh;
	struct s_obj		*next;
}						t_obj;

typedef struct			s_camera
{
	t_vec				vec;
	t_vec				norm;
	double				fov;
	t_vec				lower_left_corner;
	t_vec				horizontal;
	t_vec				vertical;
	t_vec				origin;
	double				aspect;
	t_vec				from;
	t_vec				at;
	t_vec				up;
	int					nb;
	struct s_camera		*next;
}						t_camera;

typedef struct			s_rt
{
	t_res				res;
	t_amb				amb;
	t_camera			*c;
	t_camera			*current_cam;
	int					nb_cam;
	int					save;
	t_light				*l;
	t_obj				*obj;
	t_window			window;
}						t_rt;

typedef struct			s_args
{
	int					x;
	t_rt				*rt;
}						t_args;

typedef struct			s_params
{
	double				min;
	double				max;
	t_hit				*hit;
	t_ray				ray;
}						t_params;

typedef struct			s_pc
{
	double				aspect_ratio;
	double				theta;
	double				h;
	double				viewport_height;
	double				viewport_width;
	t_vec				vup;
	t_vec				w;
	t_vec				u;
	t_vec				v;
}						t_pc;

typedef struct			s_hs
{
	t_vec				oc;
	t_vec				norm;
	double				a;
	double				half_b;
	double				c;
	double				discriminant;
	double				root;
	double				temp;
}						t_hs;

typedef struct			s_th
{
	t_vec				e1;
	t_vec				e2;
	t_vec				h;
	t_vec				s;
	t_vec				q;
	double				a;
	double				f;
	double				u;
	double				v;
	double				t;
}						t_th;

typedef struct			s_rc
{
	t_hit				hit;
	t_obj				obj;
	t_vec				n;
	t_light				*tmp;
	t_vec				col;
	double				t;
	double				dt;
	t_vec				unit_direction;
	t_vec				light_sum;
	t_hit				a;
	t_ray				shadow;
}						t_rc;

typedef struct			s_ren
{
	int					i;
	int					j;
	double				u;
	double				v;
	t_ray				r;
	t_vec				color;
	t_rt				*rt;
	t_camera			cam;
}						t_ren;

void					ray_color_helper(t_rc *rc);
void					camera_init(t_rt *rt);
double					ft_clamp(double x, double min, double max);
t_hit					face_norm(t_hit hit, t_ray ray, t_vec normal);
double					degrees_to_radians(double degrees);
int						parse(char *file, t_rt *rt);
double					ft_atof(char **s, t_rt *rt);
int						ft_atoi(char **str, t_rt *rt);
void					add_res(char *line, t_rt *rt);
void					init(t_rt *rt);
void					add_amb(char *line, t_rt *rt);
int						check_bounds_vec(t_vec vec, int min, int max);
int						check_bounds_col(t_color col);
void					error(char *s, t_rt *rt);
void					add_camera(char *line, t_rt *rt);
void					add_light(char *line, t_rt *rt);
void					add_sphere(char *line, t_obj *obj, t_rt *rt);
void					add_plane(char *line, t_obj *obj, t_rt *rt);
void					add_square(char *line, t_obj *obj, t_rt *rt);
void					add_cylinder(char *line, t_obj *obj, t_rt *rt);
void					add_triangle(char *line, t_obj *obj, t_rt *rt);
void					send_to_obj(char *line, t_rt *rt);
void					check_parse(t_rt rt);
int						spaces(char c);
t_ray					ray_get(t_camera c, double u, double v);
t_ray					ray_new(t_vec o, t_vec d);
t_vec					ray_color(t_rt *rt, t_ray ray);
t_vec					sphere_norm(t_sphere s, t_vec pi);
double					hit_sphere(t_sphere s, t_params params);
t_sphere				*create_sphere(t_vec c, double r, t_color color);
t_vec					vec_add(t_vec a, t_vec b);
t_vec					vec_sub(t_vec a, t_vec b);
t_vec					vec_mult(t_vec a, double i);
t_vec					vec_div(t_vec a, double i);
double					vec_dot(t_vec a, t_vec b);
t_vec					vec_norm(t_vec vec);
t_vec					vec_new(double x, double y, double z);
t_vec					vec_cross(t_vec a, t_vec b);
t_vec					vec_cross2(t_vec a, t_vec b);
t_vec					unit_vector(t_vec vec);
double					vec_len(t_vec vec);
void					create_window(t_window *window, t_rt *rt);
void					put_pixel(t_window window, int x, int y,
						t_vec color);
int						display(t_rt *rt);
void					*render(void *arg);
t_vec					vec_at(t_ray ray, double t);
t_sphere				sphere_new(t_vec c, double r, t_color col);
t_color					color_new(int r, int g, int b);
void					vec_print(t_vec vec);
int						program_exited(void *rt);
int						key_pressed(int key, t_rt *rt);
double					intersect(t_rt *rt, t_hit *hit, t_ray ray,
						t_obj *obj);
t_vec					color_to_vec(t_color col);
t_vec					vec_clamp(t_vec col);
int						square_hit(t_square sq, t_params params);
int						plane_hit(t_plane p, t_params params);
double					hit_get(t_obj *obj, t_params par,
						t_hit *hit, t_ray ray);
int						threads_init(t_rt *rt);
int						triangle_hit(t_triangle tr, t_params params);
t_vec					triangle_norm(t_triangle tr);
int						cylinder_hit(t_cylinder cy, t_params params);
int						base_hit(t_cylinder cy, t_ray ray, double *dist,
						t_vec c, t_vec center);
t_vec					cylinder_norm(t_cylinder cy, t_vec p);
t_vec					rotation_x(t_vec vec, double x);
t_vec					rotation_y(t_vec vec, double y);
t_vec					rotation_z(t_vec vec, double z);
t_vec					rotation(t_vec vec, t_vec angle);
void					points(t_square sq, t_vec p[4]);
t_vec					color_get(t_obj obj);
t_vec					vec_mult_vec(t_vec a, t_vec b);
int						ft_strcmp(char *s1, char *s2);
int						check_file_name(char *file, t_rt *rt);
t_window				window_init(t_rt *rt);
t_vec					get_norm(t_obj obj, t_hit hit);
void					camera_switch(t_rt *rt, int nb);
int						get_pixel(t_window *window, unsigned int x,
						unsigned int y);
void					int_to_char(int n, unsigned char *src);
int						screenshot(t_rt *rt);
void					bmp_pixels(t_rt *rt, int fd, int pad);
void					bmp_header(t_rt *rt, int fd, int filesize);
int						mouse_rotation(int b, int x, int y, t_rt *rt);
void					free_rt(t_rt *rt);
void					key_pressed_help(int key, t_rt *rt);
void					hit_sphere_helper(t_sphere s, t_params *params,
						t_hs *hs);
void					camera_init_helper(t_camera *tmp, t_pc *pc, int i,
						t_rt *rt);

#endif
