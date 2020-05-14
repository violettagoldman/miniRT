/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:51:06 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 11:51:07 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../rt.h"

void	send_to_obj(char *line, t_rt *rt)
{
	t_obj		*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		error("Error\nmalloc", rt);
	if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		add_sphere(line, obj, rt);
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		add_plane(line, obj, rt);
	else if (line[0] == 's' && line[1] == 'q' && line[2] == ' ')
		add_square(line, obj, rt);
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		add_cylinder(line, obj, rt);
	else if (line[0] == 't' && line[1] == 'r' && line[2] == ' ')
		add_triangle(line, obj, rt);
	if (rt->obj)
		obj->next = rt->obj;
	rt->obj = obj;
}

void	send_to(char *line, t_rt *rt)
{
	t_obj		*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		error("Error\nsp: malloc", rt);
	if (line[0] == 'R' && spaces(line[1]))
		add_res(line, rt);
	else if (line[0] == 'A' && spaces(line[1]))
		add_amb(line, rt);
	else if (line[0] == 'c' && spaces(line[1]))
		add_camera(line, rt);
	else if (line[0] == 'l' && spaces(line[1]))
		add_light(line, rt);
	else if ((line[0] == 's' && line[1] == 'p' && spaces(line[2])) ||
			(line[0] == 'p' && line[1] == 'l' && spaces(line[2])) ||
			(line[0] == 's' && line[1] == 'q' && spaces(line[2])) ||
			(line[0] == 'c' && line[1] == 'y' && spaces(line[2])) ||
			(line[0] == 't' && line[1] == 'r' && spaces(line[2])))
			send_to_obj(line, rt);
}

void	check_parse(t_rt rt)
{
	if ((rt.res.x == -1 && rt.res.y == -1) || rt.amb.range == -1)
		error("Error\nEmpty or not correctly formated file", &rt);
}

int		spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\f' || c == '\r' || c == ' ' ||
		c == '\v')
		return (1);
	return (0);
}

int		parse(char *file, t_rt *rt)
{
	int		fd;
	int		status;
	char	*line;

	fd = open(file, O_RDONLY);
	while ((status = get_next_line(fd, &line)) > 0)
	{
		send_to(line, rt);
		free(line);
	}
	free(line);
	check_file_name(file, rt);
	return (0);
}
