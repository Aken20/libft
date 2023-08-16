/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 03:49:04 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/15 11:10:58 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	char	*srcc;

	n = 0;
	i = 0;
	srcc = (char *)src;
	n = ft_strlen(srcc);
	if (!*dest)
	{
		return (n);
	}
	if (dstsize != 0)
	{
		while (i < n && dstsize > 1)
		{
			dest[i] = src[i];
			++i;
			--dstsize;
		}
		dest[i] = '\0';
	}
	return (n);
}
/*
int main()
{
char src[] = "hashirama";
char dest[] = "asdfghjhgfds";
char dest2[99] = "poiuytreertl";
size_t s;
s = 13;
int i = strlcpy(dest, src, s);
int k = ft_strlcpy(dest2, src, s);
printf("org: %s\t%d\n", dest, i);
printf("mine: %s\t%d\n", dest2, k);
return 0;
}
*/