/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:23:43 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/30 09:06:56 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int				i;
	int				c;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	i = 0;
	c = n;
	c_s1 = (unsigned char *) s1;
	c_s2 = (unsigned char *) s2;
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
    char b[] = "boos9ng";
    char b2[] = "boos9ng";
    int k;
	int p;
    k = memcmp(b, b2, 17);
    printf("org difrent is: %d \n", k);
    p = ft_memcmp(b, b2, 17);
    printf("my difrent is: %d", p);
    return 0;
}
*/