/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:03:28 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/14 19:48:42 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *s_in, const char *s_for, size_t len)
{
    char *c_s_in = (char *) s_in;
    char *c_s_for = (char *) s_for;
    int n = 0;

    if (c_s_for == 0 || len == 0)
    {
    return NULL;
    }
    while (*c_s_in != *c_s_for && *c_s_in)
    {
        ++c_s_in;
    }
    while(c_s_in[n] == c_s_for[n] && c_s_for[n] == '\0' && len >= 0)
    {
        if(c_s_for[n])
        {
        ++n;
        len;
        }
        else
        {
        return c_s_in;
        }
    }
    return NULL;
}

int main()
{
    char m[] = "you get hacked123";
    char m2[] = "hacked";
    char k[] = "booooring city123";
    char k2[] = "city";
    printf("org: %s\n", strnstr(m, m2, 9));
    printf("my: %s\n", ft_strnstr(k, k2, 9));
    
}