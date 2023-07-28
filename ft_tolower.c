/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 03:49:26 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/29 02:50:45 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int				i;
	unsigned char	sc;

	i = 0;
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