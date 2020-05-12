#include "../rt.h"

void	free_rt(t_rt *rt)
{
	t_light		*light;
	t_camera	*camera;
	t_obj		*obj;
	void		*tmp;
	
	light = rt->l;
	camera = rt->c;
	obj = rt->obj;
	while (light)
	{
		tmp = light;
		light = light->next;
		free(tmp);
	}
	rt->l = NULL;
	while (camera)
	{
		tmp = camera;
		camera = camera->next;
		free(tmp);
	}
	rt->c = NULL;
	while (obj)
	{
		tmp = obj;
		obj = obj->next;
		free(tmp);
	}
	rt->obj = NULL;
}
