/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:23:43 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/24 08:42:27 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int		i;
	int		c;
	char	*c_s1;
	char	*c_s2;

	i = 0;
	c = n;
	c_s1 = (char *) s1;
	c_s2 = (char *) s2;
	while (i < c)
	{
		if (c_s1[i] == c_s2[i])
		{
			++i;
		}
		else
			return (c_s1[i] - c_s2[i]);
	}
	return (0);
}
/*
int main()
{
    char b[] = "boor9ng";
    char b2[] = "boos9ng";
    int k;
    k = ft_memcmp(b, b2, 3);
    printf("the difrent is: %d \n", k);
    k = ft_memcmp(b, b2, 8);
    printf("the difrent is: %d", k);
    return 0;
}*/
