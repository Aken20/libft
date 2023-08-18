/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:16:58 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/18 21:29:01 by ahibrahi         ###   ########.fr       */
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
	if ((start == 0 && len == 0))
		return ((char *) s);
	if (start > n)
	{
		sub = malloc(1);
		if (!sub)
			return (0);
		*sub = 0;
		return (sub);
	}
	sub = malloc(len + 1);
	if (!sub)
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