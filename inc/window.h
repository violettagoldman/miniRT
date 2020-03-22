#ifndef WINDOW_H
# define WINDOW_H
#include "../minilibx/elcapitan/mlx.h"
#include "color.h"

typedef struct		s_window
{
	int		w;
	int		h;
	void	*mlx;
	void	*window;
	void	*image;
	char	*image_data;
}					t_window;

void	create_window(t_window *window);
void	put_pixel(t_window window, int x, int y, t_color color);

#endif
