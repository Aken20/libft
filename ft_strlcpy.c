/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 03:49:04 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/20 16:34:54 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	char	*c_src;
	char	*c_dest;

	n = 0;
	i = 0;
	c_src = (char *)src;
	n = ft_strlen(c_src);
	if (!dest)
		return (n);
	c_dest = (char *) dest;
	if (dstsize > 0)
	{
		while (i < n && dstsize > 1 && c_src[i])
		{
			c_dest[i] = c_src[i];
			++i;
			--dstsize;
		}
		c_dest[i] = '\0';
	}
	return (n);
}
/*
int main()
{
char src[] = "coucou";
char dest[10]; memset(dest, 'A', 10);
char dest2[10]; memset(dest, 'A', 10);
size_t s;
s = 13;
int i = strlcpy(dest, src, 2);
int k = ft_strlcpy(dest2, src, 2);
printf("org: %s\t%d\n", dest, i);
printf("mine: %s\t %d\n", dest2, k);
return 0;
}
*/