/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:02:49 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/18 18:34:26 by ahibrahi         ###   ########.fr       */
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

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	l = ft_len(s1);
	l1 = ft_len(s2);
	len = (l + l1);
	sjn = (char *) malloc(len + 1);
	if (!sjn)
		return (0);
	l = -1;
	while (s1[++l])
		sjn[l] = s1[l];
	l1 = 0;
	while (s2[l1])
		sjn[l++] = s2[l1++];
	sjn[l] = 0;
	return (sjn);
}
