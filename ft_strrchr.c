/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:52:10 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/30 10:06:43 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_slen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	*c_s;

	n = ft_slen(s);
	if (c == 0 || n == 0)
		return (0);
	--n;
	while (s[n] && n >= 0)
	{
		if (s[n] == c)
		{
			c_s = (char *)s + n;
			return (c_s);
		}
		--n;
	}
	if (s[n] == c)
	{
		c_s = (char *)s + n;
		return (c_s);
	}
	return (0);
}

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
