#include "../rt.h"

t_vec		get_norm(t_obj obj, t_hit hit)
{
	if (obj.type == 0)
		return (sphere_norm(obj.sh.sp, hit.p));
	else if (obj.type == 1)
		return (obj.sh.pl.norm);
	else if (obj.type == 2)
		return (obj.sh.sq.norm);
	else if (obj.type == 3)
		return (cylinder_norm(obj.sh.cy, hit.p));
	else if (obj.type == 4)
		return (triangle_norm(obj.sh.tr));
	return (vec_new(0, 0, 1));
}
