/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:31:29 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/14 18:38:01 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void *ft_memmove(void *dest, const void *src, int n)
{
    char *c_dest = (char *) dest;
    char *c_src = (char *) src;
    int i;
    i = 0;
    if (c_src > c_dest)
    {
        i = 0;
        while(i < n)
        {
            c_dest[i] = c_src[i];
            ++i;
        }
        return 0;
    }
    else if (c_src < c_dest)
    {
        i = --n;
        while (i >= 0)
        {
        c_dest[i] = c_src[i];
        --i;    
        }
        return 0;
    }
        return dest;
}
int main()
{
    char src[] = "12345";
    char src2[] = "12345";
    ft_memmove(src + 2, src , 2);
    printf("my memmove %s\n", src);
    memmove(src2 + 2, src2 , 2);
    printf("memmove %s\n", src);
    ft_memmove(src , src +2, 4);
    printf("my memmove %s\n", src);
    memmove(src2 , src2 +2, 4);
    printf("memmove %s\n", src);
    return 0;
}