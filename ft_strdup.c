/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aken <aken@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:04:09 by aken              #+#    #+#             */
/*   Updated: 2023/07/27 21:39:20 by aken             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	n;
	char	*dup;

	n = 0;
	while (s[n])
	{
		n++;
	}
	if (n == 0)
	{
		return (NULL);
	}
	dup = (char *) malloc(n);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	//dup[i] = '\0';
	return (dup);
}

int main()
{
	char	a[] = "kamihamiha";
	char	*b;
	char	*c;

	b = strdup(a);
	c = ft_strdup(a);
	printf("org: %s\n", b);
	printf("mine: %s\n", c);
}
