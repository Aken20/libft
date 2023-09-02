/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:07 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/24 02:39:40 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	c;
	size_t	n;
	size_t	k;

	i = 0;
	if (dest == 0 && size == 0)
		return (0);
	c = ft_strlen(dest);
	n = ft_strlen(src);
	if (size < c)
		return (n + size);
	k = c;
	while (i + 1 < size - k && src[i])
	{
		*(dest + c) = *(src + i);
		i++;
		c++;
	}
	dest[c] = (0);
	if (size >= k)
		return (k + n);
	else 
		return (size + n);
}
/*
int main()
{
char src[] = " im going to";
char dest[30] = "mindok";
char dest2[30] = "mindok";
size_t s;
s = 30;
int i = strlcat(dest, src, s);
int k = ft_strlcat(dest2, src, s);
printf("org: %s\t%d\n", dest, i);
printf("mine: %s\t%d\n", dest2, k);
return 0;
}
*/