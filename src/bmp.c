#include "../rt.h"

void	bmp_header(t_rt *rt, int fd, int filesize)
{
	int						i;
	unsigned char			data[54];

	i = -1;
	while (++i < 54)
		data[i] = 0;
	data[0] = (unsigned char)('B');
	data[1] = (unsigned char)('M');
	int_to_char(filesize, data + 2);
	data[10] = (unsigned char)(54);
	data[14] = (unsigned char)(40);
	int_to_char((unsigned int)rt->window.w, data + 18);
	int_to_char((unsigned int)rt->window.h, data + 22);
	data[26] = (unsigned char)(1);
	data[28] = (unsigned char)(24);
	write(fd, data, 54);
}

void	bmp_pixels(t_rt *rt, int fd, int padding)
{
	unsigned char	zero[3];
	int				i;
	int				j;
	int				color;

	i = -1;
	while (++i < 3)
		zero[i] = 0;
	i = 0;
	while (i < rt->window.h)
	{
		j = 0;
		while (j < rt->window.w)
		{
			color = get_pixel(&(rt->window), j, i);
			write(fd, &color, 3);
			j++;
		}
		write(fd, &zero, padding);
		i++;
	}
}

int		screenshot(t_rt *rt)
{
	int			fd;
	int			filesize;
	int			pad;

	pad = (4 - (rt->window.w * 3) % 4) % 4;
	filesize = 54 + ((3 * rt->window.w + pad) * rt->window.h);
	if ((fd = open("picture.bmp", O_WRONLY | O_CREAT |
					O_TRUNC | O_APPEND, 0666)) < 0)
		return (0);
	bmp_header(rt, fd, filesize);
	bmp_pixels(rt, fd, pad);
	close(fd);
	return (1);
}

void	int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

int		get_pixel(t_window *window, unsigned int x, unsigned int y)
{
	int	ptr;

	ptr = *(int*)(window->image_data
			+ (4 * (int)window->w * ((int)window->h - 1 - y))
			+ (4 * x));
	return ((ptr & 0xFF0000) | (ptr & 0x00FF00) | (ptr & 0x0000FF));
}
