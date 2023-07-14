/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:27:38 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/14 19:36:24 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int ft_atoi(const char *str)

{
    int i;
    i = 0;
    int *k;
    if (str[i] == 0)
    {
        return 0;
    }
    while(str[i])
    {
		if	(str[i]	>=	48	&&	str[i] <= 57)
		{
			k[i] = str[i];
			++i;
        }
        else
        {
            return 0;
        }
    }
    if (k[i])
    {
        return *k;
    }
    return 0;
}

int main ()
{
    char s[] = "145nfnkff";
    char s2[] = "145nfnkff";
    int c = ft_atoi(s);
    int c2 = atoi(s2);
    printf("mine:%d\n%d\n", c, c2);
    return 0;
}