/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:56:44 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/24 01:47:47 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_c(char const *s, char c)
{
	int	cc;
	int	i;

	i = 0;
	cc = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			i++;
			cc++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (cc);
}

static	int	ft_end(char const *s, char c, int start)
{
	if (s[start] && s[start] != c)
	{
		while (s[start] && s[start] != c)
			start++;
		return (start - 1);
	}
	return (start);
}

static	char	**ft_set(char const *s, char **d, char c, int cc)
{
	int		start;
	int		end;
	int		n;
	int		l;
	int		len;

	len = ft_strlen(s);
	l = 0;
	n = 0;
	start = 0;
	while (l < cc && start <= len)
	{
		while (s[start] && s[start] == c)
			start++;
		end = ft_end(s, c, start);
		d[l] = malloc(sizeof(char) * (end - start + 2));
		if (!d[l])
			return (0);
		n = 0;
		while (start <= end && start <= len)
			d[l][n++] = s[start++];
		d[l][n] = 0;
		l++;
	}
	return (d);
}

char	**ft_split(char const *s, char c)
{
	char	**d;
	int		cc;

	if (!s)
		return (0);
	cc = ft_c(s, c);
	d = malloc(sizeof(char *) * (cc + 1));
	if (!d)
		return (0);
	d = ft_set(s, d, c, cc);
	d[cc] = (void *)0;
	return (d);
}
/*
int main()
{
	char *s = "split  ||this|for|me|||||!|";
	char **result = ft_split(s, '|');
	int i = 0;
	while (i <= 5)
	{
		printf("%s\n",result[i]);
		i++;
	}
}
*/