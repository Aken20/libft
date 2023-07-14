/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 03:49:04 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/13 03:35:14 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t size)

{
    int i;
    int n;
    n = 0;
    i = 0;
    while(dest[i] == 0 || dest[i])
    {
    ++n;
    }
    if(n >= size - 1)
    {
        while(i < size - 1 && dest[i] == 0)
        {
            dest[i] = src[i];
            ++i;
        }
    }
        return i;
}

int main ()

{
char src[] = "hashirama";
char dest[5];
char dest2[5];
size_t s;
s = 5;
strlcpy(dest, src, s);
ft_strlcpy(dest2, src, s);
printf("org: %s\n", dest);
printf("mine: %s\n", dest2);
return 0;
}