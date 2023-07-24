/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:15:48 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/07/24 11:16:41 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] >= 97 && c[i] <= 122)
		{
			c[i] -= 32;
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
char c[] = "abcdefgoudj";
ft_toupper (c);
while (c[i] != 0)
{
write (1, &c[i], 1);
++i;
}
write (1, "\n", 1);

return 0;
}
*/