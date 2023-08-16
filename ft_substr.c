/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:16:58 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/15 11:28:09 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub; 
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	while (s[n])
		n++;
	if (start > n)
	{
		sub = ft_calloc(1, 1);
		return (sub);
	}
	if (len == 0)
		return (0);
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = 0;
	return (sub);
}
/*
int	main(void)
{
	char	s[] = "y9";
	char	*k;

	k = ft_substr(s, 0, 1);
	printf("is :%s\n", k);
}
*/