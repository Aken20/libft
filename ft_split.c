/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:56:44 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/18 17:57:03 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (cc + 1);
}

static	int	ft_len(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

static	int	ft_end(char const *s, char c, int start)
{
	if (s[start] && s[start] != c)
	{
		while (s[start] && s[start] != c)
		{
			start++;
		}
		return (start - 1);
	}
	return (start);
}

char	**ft_split(char const *s, char c)
{
	int		start;
	int		end;
	char	**d;
	int		n;
	int		l;

	l = 0;
	n = 0;
	start = 0;
	if (s && c)
	{
		d = malloc(sizeof(char *) * (ft_c(s, c)));
		if (!d)
			return (0);
	}
	while (s && c && d && start <= ft_len(s))
	{
		while (s[start] == c)
			start++;
		end = ft_end(s, c, start);
		d[l] = malloc(sizeof(char) * (end - start) + 1);
		if (!d[l])
			return (0);
		n = 0;
		while (start <= end && start <= ft_len(s))
			d[l][n++] = s[start++];
		l++;
	}
	if (d)
		return (d);
	return (0);
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