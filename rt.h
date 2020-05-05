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
# include "./minilibx/elcapitan/mlx.h"
# define PI 3.1415926535897932385

typedef struct		s_vec
{
	double	x;
	double	y;
	double	z;
}					t_vec;

typedef struct		s_color
{
	int r;
	int g;
	int b;
}					t_color;

typedef struct		s_ray
{
	t_vec o;
	t_vec d;
}					t_ray;

typedef struct		s_plane
{
	t_vec	vec;
	t_vec	norm;
	t_color	col;
}					t_plane;

typedef struct		s_sphere
{
	t_vec			c;
	double			r;
	t_color			col;
}					t_sphere;

typedef struct		s_square
{
	t_vec	vec;
	t_vec	norm;
	double	size;
	t_color	col;
}					t_square;

typedef struct		s_triangle
{
	t_vec	first;
	t_vec	second;
	t_vec	third;
	t_color	col;
}					t_triangle;

typedef struct		s_cylinder
{
	t_vec	vec;
	t_vec	norm;
	double	d;
	double	h;
	t_color	col;
}					t_cylinder;

typedef struct		s_window
{
	int		w;
	int		h;
	void	*mlx;
	void	*window;
	void	*image;
	char	*image_data;
}					t_window;

typedef struct		s_hit
{
    t_vec	p;
    t_vec	norm;
    double	t;
    int		front;
}					t_hit;

typedef struct		s_light
{
	t_vec			vec;
	double			bright;
	t_color			col;
	struct s_light	*next;
}					t_light;

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

typedef struct		s_camera
{
	// at = vec + norm
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
	struct s_camera		*next;
}					t_camera;

typedef struct		s_rt
{
	t_res		res;
	t_amb		amb;
	t_camera	*c;
	t_light		*l;
	t_obj		*obj;
	t_window	window;
}									t_rt;

void		camera_init(t_rt *rt);
double		ft_clamp(double x, double min, double max);
t_hit		face_norm(t_hit hit, t_ray ray, t_vec normal);
double		degrees_to_radians(double degrees);
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
t_ray		ray_get(t_camera c, double u, double v);
t_ray		ray_new(t_vec o, t_vec d);
t_vec		ray_color(t_rt *rt, t_ray ray);
t_vec		sphere_norm(t_sphere s, t_vec pi);
double		hit_sphere(t_sphere s, double min, double max, t_hit *hit, t_ray ray);
t_sphere	*create_sphere(t_vec c, double r, t_color color);
t_vec		vec_add(t_vec a, t_vec b);
t_vec		vec_sub(t_vec a, t_vec b);
t_vec		vec_mult(t_vec a, double i);
t_vec		vec_div(t_vec a, double i);
double		vec_dot(t_vec a, t_vec b);
t_vec		vec_norm(t_vec vec);
t_vec		vec_new(double x, double y, double z);
t_vec		vec_cross(t_vec a, t_vec b);
t_vec		unit_vector(t_vec vec);
double		vec_len(t_vec vec);
void		create_window(t_window *window);
void		put_pixel(t_window window, int x, int y, t_vec color);
int			display(t_rt *rt);
t_window	window_init();
void		render(t_rt *rt);
t_window	smth();
t_vec		vec_at(t_ray ray, double t);
t_sphere	sphere_new(t_vec c, double r, t_color col);
t_color		color_new(int r, int g, int b);
void		vec_print(t_vec vec);
int			program_exited(void *rt);
int			key_pressed(int key, t_rt *rt);
double		intersect(t_rt *rt, t_hit *hit, t_ray ray, t_obj *obj);
t_light		light_new(t_vec vec, double bright, t_color col);
t_vec		color_to_vec(t_color col);
t_vec		vec_clamp(t_vec col);
int			square_hit(t_square sq, double min, double max, t_hit *hit, t_ray ray);
int			plane_hit(t_plane p, double min, double max, t_hit *hit, t_ray ray);
double		hit_get(t_obj *obj, double min, double closest, t_hit *hit, t_ray ray);

#endif
