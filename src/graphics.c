#include "../rt.h"

void		create_window(t_window *window, t_rt *rt)
{
	int	bits_pixel;
	int	line_size;
	int	endian;

	bits_pixel = 32;
	line_size = 4 * window->w;
	endian = 0;
	window->mlx = mlx_init();
	if (rt->save == 0)
		window->window = mlx_new_window(window->mlx, window->w, window->h,
	"miniRT by Violetta Goldman");
	window->image = mlx_new_image(window->mlx, window->w, window->h);
	window->image_data = mlx_get_data_addr(window->image, &bits_pixel,
	&line_size, &endian);
}

void		put_pixel(t_window window, int x, int y, t_vec color)
{
	int	index;

	if (x >= window.w || x < 0 || y < 0 || y >= window.h)
		return ;
	index = x * 4 + y * 4 * window.w;
	window.image_data[index + 0] = (char)(256 * ft_clamp(color.z, 0.0, 0.999));
	window.image_data[index + 1] = (char)(256 * ft_clamp(color.y, 0.0, 0.999));
	window.image_data[index + 2] = (char)(256 * ft_clamp(color.x, 0.0, 0.999));
	window.image_data[index + 3] = (char)0;
}

int			display(t_rt *rt)
{
	threads_init(rt);
	mlx_put_image_to_window(rt->window.mlx, rt->window.window,
	rt->window.image, 0, 0);
	return (1);
}

t_window	window_init(t_rt *rt)
{
	create_window(&rt->window, rt);
	if (rt->save == 0)
	{
		mlx_put_image_to_window(rt->window.mlx, rt->window.window, rt->window.image, 0, 0);
		mlx_hook(rt->window.window, 2, 1L << 0, &key_pressed, rt);
		mlx_mouse_hook(rt->window.window, &mouse_rotation, rt);
		mlx_hook(rt->window.window, 17, 1L << 17, &program_exited, rt);
	}

	mlx_loop_hook(rt->window.mlx, &display, rt);
	mlx_loop(rt->window.mlx);
	return (rt->window);
}
