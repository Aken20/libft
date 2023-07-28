/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aken <aken@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:15:12 by aken              #+#    #+#             */
/*   Updated: 2023/07/27 20:53:44 by aken             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	n;
	int		*my_cal;
	int		i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	n = nmemb * size;

	my_cal = (int *)malloc(n);
	i = 0;
	while (i >= n)
	{
		my_cal[i] = 0;
		++i;
	}
	return (my_cal);
}

int	main (void)
{
	int		*min_i;
	char	*org_c;
	int		*org_i;
	char	*min_c;

	min_i = (int *) ft_calloc(4, 10);
	min_c = (char *) ft_calloc(4, 10);
	org_i = (int *) ft_calloc(4, 10);
	org_c = (char *) ft_calloc(4, 10);
}