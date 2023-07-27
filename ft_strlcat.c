/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:07 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/27 13:28:04 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int	i;
	int	n;
	int	c;

	n = 0;
	i = 0;
	c = 0;
	while (src[n])
	{
		++n;
	}
	while (dest[c])
	{
		++c;
	}
	n = n + c;
	while (size > c && size != 0 && n != 0)
	{
		dest[c] = src[i];
		++c;
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

int main()
{
char src[] = "hashirama";
char dest[7] = "mindok";
char dest2[7] = "mindok";
size_t s;
s = 7;
int i = strlcat(dest, src, s);
int k = ft_strlcat(dest2, src, s);
printf("org: %s\t%d\n", dest, i);
printf("mine: %s\t%d\n", dest2, k);
return 0;
}
