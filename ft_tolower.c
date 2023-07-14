/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 03:49:26 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/06 17:59:41 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int ft_tolower (char *c)
{
    int i;
    i = 0;
    while (c[i] != '\0')
    {
        if ( c[i] >= 65 && c[i] <= 90)
        {
        c[i] += 32;
        ++i;
        }
        else
        {
        ++i;
        }
    }
return (*c);
}
/*
int main (void)
{
int i;
i = 0;
char c[] = "AbHFTFdc2233  defgoudZ";
ft_tolower (c);
while (c[i] != 0)
{
write (1, &c[i], 1);
++i;
}
write (1, "\n", 1);

return 0;
}
*/