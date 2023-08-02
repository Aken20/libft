/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:09:48 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/02 16:26:28 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	int				i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (p1[i] && p2[i] && --n)
	{
		if (p1[i] == p2[i])
		{
			++i;
		}
		else
		{
			return (p1[i] - p2[i]);
		}
	}
	return (p1[i] - p2[i]);
}
/*
int main(void)
{
    int k;
    char *s1;
    char *s2;
    s1 = "kamisama";
    s2 = "kamindoksi";
    k = ft_strncmp( s1, s2, 8);
    write(1, k, 3);
    write(1, "\n", 1);
    s1 = "kamisama1";
    s2 = "kamisama0";
    k = ft_strncmp( s1, s2, 8);
    write(1, k, 3);
    write(1, "\n", 1);
    s1 = "mamindoksai";
    s2 = "mamindoksai";
    k = ft_strncmp( s1, s2, 8);
    write(1, k, 1);
    write(1, "\n", 1);
}
*/