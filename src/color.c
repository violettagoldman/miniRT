#include "../rt.h"

t_color		color_new(int r, int g, int b)
{
	t_color c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_vec		color_to_vec(t_color col)
{
	t_vec vec;

	vec.x = (double)col.r / 255;
	vec.y = (double)col.g / 255;
	vec.z = (double)col.b / 255;
	return (vec);
}

t_vec		vec_clamp(t_vec col)
{
	t_vec vec;

	vec.x = (double)ft_clamp(col.x, 0, 0.999);
	vec.y = (double)ft_clamp(col.y, 0, 0.999);
	vec.z = (double)ft_clamp(col.z, 0, 0.999);
	return (vec);
}
