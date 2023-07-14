/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:54:30 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/11 15:01:49 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

void *ft_memchr(const void *s, int c, int n)
{
    int i;
    i = 0;
    char *c_s = (char *) s;
    while (n >= 0)
    {
        if (*c_s != c)
        {
         ++c_s;
         --n;
        }
        else if (*c_s == c)
        {
        return c_s;   
        }
    }
    return NULL;
}

int main()
{
char s[] = "mindoksai";
int c;
c = 'p';
char *ptr = memchr (s, c, 7);
printf("str: %s\n", ptr);
char *mptr = ft_memchr (s, c, 7);
printf("my str: %s\n", mptr);
}