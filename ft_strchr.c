/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:35:35 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/11 13:01:17 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
    int i;
    i = 0;
    while (s)
    {
        if (*s != c)
        {
         ++s;
        }
        else
        {
        char *c_s = (char *) s;
        return c_s;   
        }
    }
    return NULL;
}

int main()
{
char s[] = "minkdoksai";
int c;
c = 'k';
char *ptr = strchr (s,c);
printf("str: %s\n", ptr);
char *mptr = ft_strchr (s,c);
printf("my str: %s\n", mptr);
}