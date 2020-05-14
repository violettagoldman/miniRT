/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:50:58 by vgoldman          #+#    #+#             */
/*   Updated: 2020/05/14 21:05:27 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int		check_file_name(char *file, t_rt *rt)
{
	int len;

	len = 0;
	while (file[len])
		len++;
	if (file[len - 1] != 't' || file[len - 2] != 'r' || file[len - 3] != '.')
	{
		error("Error\nFile name error", rt);
		return (0);
	}
	return (1);
}
