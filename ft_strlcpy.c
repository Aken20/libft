/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 03:49:04 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/24 09:45:06 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (src[n])
	{
		++n;
	}
	while (i < size - 1 && dest[i] == 0)
	{
		dest[i] = src[i];
		++i;
	}
	return (n);
}
/*
int main()
{
char src[] = "hashirama";
char dest[5];
char dest2[5];
size_t s;
s = 5;
int i = strlcpy(dest, src, s);
int k = ft_strlcpy(dest2, src, s);
printf("org: %s\t%d\n", dest, i);
printf("mine: %s\t%d\n", dest2, k);
return 0;
}
*/