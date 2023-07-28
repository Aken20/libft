/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:27:50 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/29 01:51:13 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, int n)
{
	char	*c_dest;
	char	*c_src;
	int		i;

	i = 0;
	c_dest = (char *) dest;
	c_src = (char *) src;
	if (dest || src)
	{
		while (i < n)
		{
			c_dest[i] = c_src[i];
			++i;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[6];
	char	src2[6];

	src[6] = "12345";
	src2[6] = "12345";
	ft_memcpy(src + 2, src, 3);
	printf("my memcpy %s\n", src);
	memcpy(src2 + 2, src2, 3);
	printf("memcpy %s\n", src);
//
	ft_memcpy(src, src +2, 4);
    printf("my memcpy %s\n", src);
    memcpy(src2 , src2 +2, 4);
    printf("memcpy %s\n", src);
    return 0;
}
*/