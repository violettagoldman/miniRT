#include "../inc/window.h"

void	create_window(t_window *window)
{
	int	bits_pixel = 32;
	int	line_size = 4 * window->w;
	int	endian = 0;

	window->mlx = mlx_init();
	window->window = mlx_new_window(window->mlx, window->w, window->h,
	"miniRT by Violetta Goldman");
	window->image = mlx_new_image(window->mlx, window->w, window->h);
	window->image_data = mlx_get_data_addr(window->image, &bits_pixel,
	&line_size, &endian);
}

void	put_pixel(t_window window, int x, int y, t_color color)
{
	int	index;

	index = x * 4 + y * 4 * window.w;
	window.image_data[index + 0] = color.b;
	window.image_data[index + 1] = color.g;
	window.image_data[index + 2] = color.r;
	window.image_data[index + 3] = 0;
}
