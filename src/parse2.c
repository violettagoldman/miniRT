/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:50:58 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 11:50:59 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int		check_file_name(char *file, t_rt *rt)
{
	while (*file != '.')
		file++;
	if (ft_strcmp(file, ".rt"))
	{
		error("Error\nFile name error", rt);
		return (0);
	}
	return (1);
}
