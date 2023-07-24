/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:09:48 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/24 09:46:26 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && --n)
	{
		if (s1[i] == s2[i])
		{
			++i;
		}
		else
		{
			return (s1[i] - s2[i]);
		}
	}
	return (s1[i] - s2[i]);
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