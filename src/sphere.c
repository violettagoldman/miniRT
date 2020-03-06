#include "../inc/sphere.h"
#include "../inc/vec.h"
#include "../inc/ray.h"
#include <stdlib.h>

t_sphere	*create_sphere(t_vec c, double r)
{
	t_sphere *sphere;

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sphere->c = c;
	sphere->r = r;
	return (sphere);
}
