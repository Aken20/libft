/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 03:49:04 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/29 00:36:07 by ahibrahi         ###   ########.fr       */
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
	while (i < n && size != 0 && n != 0)
	{
		dest[i] = src[i];
		++i;
		--size;
	}
	while (size)
	{
		dest[i] = 0;
		--size;
		++i;
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