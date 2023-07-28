/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:02:49 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/29 00:51:57 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(const char *str)
{
	int	len;

	len = 0; 
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	int		l1;
	int		len;
	char	*sjn;

	l = ft_len(s1);
	l1 = ft_len(s2);
	len = l + l1;
	sjn = (char *) malloc(len);
	l = 0;
	while (s1[l])
	{
		sjn[l] = s1[l];
		++l; 
	}
	l1 = 0;
	while (s2[l1])
	{
		sjn[l] = s1[l1];
		++l1;
	}
	return (sjn);
}
