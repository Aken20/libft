/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:07 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/28 09:30:37 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(const char *str)
{
	int	len;

	while (str[len])
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int	i;
	int	c;
	int	n;
	int	k;

	i = 0;
	c = ft_len(dest);
	n = ft_len(src);
	if (size < c)
		return (n + size);
	k = c;
	while (i < size - k)
	{
		dest[c] = src[i];
		i++;
		c++;
	}
	dest[c] = (0);
	if (size >= k)
		return (k + n);
	else 
		return (size + n);
}

int main()
{
char src[] = "hashiramertyuiopoiuykkooaa";
char dest[51] = "mindok";
char dest2[51] = "mindok";
size_t s;
s = 21;
int i = strlcat(dest, src, s);
int k = ft_strlcat(dest2, src, s);
printf("org: %s\t%d\n", dest, i);
printf("mine: %s\t%d\n", dest2, k);
return 0;
}
