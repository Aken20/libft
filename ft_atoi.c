/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 06:50:44 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/03 08:58:36 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check(const char *str)
{
	int	i;
	int	c;
	int	ret;

	ret = -1;
	c = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ret = 0;
		i++;
	}
	while (str[i] == 48)
		i++;
	while (str[i] >= 48 && str[i++] <= 57)
		c++;
	if (c >= 19)
		return (ret);
	return (2);
}

int	ft_atoi(const char *str)
{
	int			s;
	int			aoi;
	int			i;

	i = 0;
	s = 1;
	if (str[i] == 0)
		return (0);
	if (ft_check(str) != 2)
		return (ft_check(str));
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		++i;
	}
	if (str[i] >= 48 && str[i] <= 57)
		aoi = (str[i++] - 48);
	else 
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
		aoi = (aoi * 10) + (str[i++] - 48);
	return (aoi * s);
}

/* int	main(void)
{
	char *n = "+999999999999999999";
	int i1 = atoi(n);
	int i2 = ft_atoi(n);
	printf("min %i\n", i2);
	printf("org %i\n", i1);
} */
