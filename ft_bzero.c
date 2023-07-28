/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aken <aken@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:37:49 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/24 10:56:13 by aken             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, int n)
{
	char	*c_s;

	c_s = (char *) s;
	while (n > 0)
	{
		*c_s = 0;
		--n;
		++c_s;
	}
	return (c_s);
}

/* int main()
{
    char s[] = "boooring";
    char s2[] = "boooring";
    ft_bzero(s, 2);
    bzero(s2, 2);
    printf("my: %s\n", s);
    printf("org: %s\n", s2);
} */