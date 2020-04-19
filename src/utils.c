#include <stdio.h>
#include "../inc/parse.h"

int		ft_atoi(char **str)
{
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	while (**str == '\t' || **str == '\n' || **str == '\f' || **str == '\r' ||
			**str == ' ' || **str == '\v' || **str == ',')
		(*str)++;
	if (**str == '-')
	{
		sign *= -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	if (!(**str >= '0' && **str <= '9'))
		error("Error\nBadly formated file");
	while (**str && **str >= '0' && **str <= '9')
	{
		res = (res * 10) + (**str - '0');
		(*str)++;
	}
	return (res * sign);
}

double		ft_atof(char **s)
{
 	int		integer;
 	double	res;

 	integer = ft_atoi(s);
 	if (*s && **s == '.')
 	{
 		(*s)++;
 		res = (double)ft_atoi(s);
 	}
 	else
 		res = 0;
 	while (res >= 1)
 		res /= 10;
 	res += integer;
 	return (res);
 }
