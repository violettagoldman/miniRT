/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:49:26 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 16:59:02 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

static void	free_rt_help(t_rt *rt)
{
	t_obj	*obj;
	void	*tmp;

	obj = rt->obj;
	while (obj)
	{
		tmp = obj;
		obj = obj->next;
		free(tmp);
	}
	rt->obj = NULL;
}

void		free_rt(t_rt *rt)
{
	t_light		*light;
	t_camera	*camera;
	void		*tmp;

	light = rt->l;
	camera = rt->c;
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
	free_rt_help(rt);
}
