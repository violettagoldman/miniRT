#include "../inc/window.h"
#include "../inc/ray.h"

int	main(void)
{
	t_window	window;
	t_color		color;

	color.r = 0;
	color.g = 0;
	color.b = 255;
	window.w = 500;
	window.h = 500;
	create_window(&window);
	put_pixel(window, 10, 10, color);
	mlx_put_image_to_window(window.mlx, window.window, window.image, 0, 0);
	mlx_loop(window.mlx);
	return (0);
}
