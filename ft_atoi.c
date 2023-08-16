/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 06:50:44 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/15 11:04:52 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_change(int t)
{
	int	k;

	k = t - 48;
	return (k);
}

int	ft_sign(const char *str, int i)
{
	if (str[i] == '-')
	{
		return (-1);
	}
	if (str[i] == '+')
	{
		return (1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	s;
	int	aoi;
	int	i;

	i = 0;
	s = 1;
	if (str[i] == 0)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		s = ft_sign(str, i);
		++i;
	}
	if (str[i] >= 48 && str[i] <= 57)
		aoi = ft_change(str[i++]);
	else 
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		aoi = (aoi * 10) + ft_change(str[i]);
		++i;
	}
	return (aoi * s);
}
/*
int	main(void)
{
	char *n = "\t\v\f\r\n \f- \f\t\n\r    06050";
	int i1 = atoi(n);
	int i2 = ft_atoi(n);
	printf("min %i\n", i2);
	printf("org %i\n", i1);
}
*/