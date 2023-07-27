/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 06:50:44 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/27 11:54:09 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_change(int t)
{
	int	k;

	k = t - 48;
	return (k);
}

int	ft_sign(const char *str, int s, int i)
{
	if (str[i] == '-')
	{
		s = -1;
	}
	return (s);
}

int	ft_atoi(const char *str)
{
	int	s;
	int	aoi;
	int	i;

	s = 1;
	i = 0;
	if (str[i] == 0)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		s = ft_sign(str, s, i);
		++i;
	}
	if (str[i] >= 48 && str[i] <= 57)
	{
		aoi = ft_change(str[i]);
		++i;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		aoi = (aoi * 10) + ft_change(str[i]);
		++i;
	}
	return (aoi * s);
}

int	main(void)
{
	char	s[] = "    +4544fk776";
	int		at;
	int		aoi;

	at = ft_atoi(s);
	aoi = atoi(s);
	printf("min %i\n", at);
	printf("org %d\n", aoi);
}
