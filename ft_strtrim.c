/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:48:34 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/18 21:36:48 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_set_start(char const *s1, char const *set, size_t n)
{
	size_t	l;

	l = 0;
	if (s1[n] && set[l])
	{
		while (s1[n] == set[l] && set[l] != 0)
		{
			n++;
			l = 0;
			while (s1[n] != set[l] && set[l] != 0)
				++l;
		}
	}
	return (n);
}

size_t	ft_set_end(char const *s1, char const *set, size_t n)
{
	size_t	l;

	l = 0;
	if (s1[n] && set[l])
	{
		while (s1[n] == set[l] && set[l] != 0)
		{
			n--;
			l = 0;
			while (s1[n] != set[l] && set[l] != 0)
				++l;
		}
	}
	return (n);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	start;
	size_t	end;
	size_t	n;

	n = 0;
	if ((s1 && set) && (*s1 != 0 && *set != 0))
		start = ft_set_start(s1, set, n);
	else
	{
		s = "";
		return (s);
	}
	while (s1[n])
		n++;
	end = ft_set_end(s1, set, n - 1);
	s = malloc((end - start + 1));
	if (!s)
		return (NULL);
	n = 0;
	while (s1[start] && start <= end)
		s[n++] = s1[start++];
	s[n] = 0;
	return (s);
}
/*
int	main(void)
{
	char *s1 = "lorem \n ipsum \t dolor \n sit \t amet";;
	char *s2 = "Hello \t  Please\n Trim me !";
	char *ret = ft_strtrim(s1, " \n\t");
	
	printf("mine: %s\n right: %s\n", ret, s2);
	return (0);
}
*/