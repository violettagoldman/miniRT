#include "../rt.h"

t_color		color_new(int r, int g, int b)
{
	t_color c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}
