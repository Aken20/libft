/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aken <aken@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:15:48 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/04 02:27:34 by aken             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	cc;

	if (c >= 97 && c <= 122)
	{
		cc = c - 32;
		return (cc);
	}
	else
		return (c);
}
/*
int main (void)
{
int i;
i = 0;
char c[] = "abcdefgoudj";
char *cc;
*cc = ft_toupper (c);
while (cc[i] != 0)
{
write (1, &cc[i], 1);
++i;
}
write (1, "\n", 1);

return 0;
}
*/