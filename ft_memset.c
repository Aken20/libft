/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:58:42 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/24 09:34:07 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, unsigned int len)
{
	int		i;
	char	*c_b;
	int		l;

	i = 0;
	l = len;
	c_b = (char *) b;
	while (i < l)
	{
		c_b[i] = c;
		++i;
	}
	return (b);
}
/*
int main ()
{
    char k[] = "hello";
    char t;
    t = '3';
    int j;
    j = 'm';
    ft_memset(k, t, 3);
    ft_memset(k + 3, j, 2);
    printf("k: %s", k);
}
*/