#include "../rt.h"

t_light light_new(t_vec vec, double bright, t_color col)
{
	t_light l;

	l.vec = vec;
	l.bright = bright;
	l.col = col;
	return (l);
}
