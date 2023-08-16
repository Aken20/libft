/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:56:44 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/16 06:09:39 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_end(char const *s, char c, int start)
{
	if (s[start] && s[start] == c)
	{
		while (s[start] != c)
		{
			start++;
		}
		return (start - 1);
	}
	else if (s[start])
		return (start);
	else 
		exit (0);
}

char	**ft_set(char **d, char *k, int l)
{
	while (k != 0)
		d[l++] = &*k++;
	return (d);
}

char	**ft_split(char const *s, char c)
{
	size_t	start;
	size_t	end;
	char	**d;
	char	*k;
	int		n;

	n = 0;
	start = 0;
	if (!s && !c)
		return (0);
	while (s && c)
	{
		while (s[start] != c)
			++start;
		while (s[start] == c)
			start++;
		end = ft_end(s, c, start);
		k = malloc((end - start) + 1);
		while (start <= end)
			k[n++] = s[start++];
		n = 0;
		if (!k)
			return (0);
		if (k)
			while (*d[n])
				n++;
		d = ft_set(d, k, n);
		free(k);
	}
	if (d)
		return (d);
	else 
		return (0);
}
