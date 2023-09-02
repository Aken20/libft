/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:52:10 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/24 03:43:16 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	*c_s;

	n = ft_strlen(s);
	if (c == 0)
	{
		c_s = (char *)(s + n);
		return (c_s);
	}
	--n;
	while (s[n] && n > 0)
	{
		if (s[n] == c)
		{
			c_s = (char *)s + n;
			return (c_s);
		}
		--n;
	}
	if ((unsigned char)s[n] == (unsigned char)c)
	{
		c_s = (char *)s + n;
		return (c_s);
	}
	return (0);
}
/*
int main()
{
char s[] = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
int c;
c = 'k';
char *ptr = strrchr (s,c);
printf("str: %s\n", ptr);
char *mptr = ft_strrchr (s,c);
printf("my str: %s\n", mptr);
}
*/