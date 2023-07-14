/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:27:50 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/11 09:59:00 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void *ft_memcpy(void *dest, void *src, int n)
{
    int i;
    i = 0;
    char *c_dest = (char *) dest;
    char *c_src = (char *) src;
    if (dest == NULL)
    {
        return NULL;
    }
    while (i < n)
    {
        c_dest[i] = c_src[i];
        ++i;
    }
    return dest;
}

int main(void)
{
        char src[] = "12345";
    char src2[] = "12345";
    ft_memcpy(src + 2, src , 2);
    printf("my memcpy %s\n", src);
    memcpy(src2 + 2, src2 , 2);
    printf("memcpy %s\n", src);
    ft_memcpy(src , src +2, 4);
    printf("my memcpy %s\n", src);
    memcpy(src2 , src2 +2, 4);
    printf("memcpy %s\n", src);
    return 0;
}