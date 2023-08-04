/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aken <aken@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 03:49:26 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/04 02:27:47 by aken             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	sc;

	if (c >= 65 && c <= 90)
	{
		sc = c + 32;
		return (sc);
	}
	else
		return (c);
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