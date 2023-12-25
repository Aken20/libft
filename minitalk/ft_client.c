/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:20:22 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/12/05 10:50:41 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send(char *s, int pid)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 48)
			kill(pid, SIGUSR1);
		if (s[i] == 49)
			kill(pid, SIGUSR2);
		i++;
		usleep (500);
	}
	free(s);
	return ;
}

static char	*ft_strrev(char *s, int len)
{
	int		i;
	char	*ms;

	i = 0;
	len = 8;
	ms = (char *)malloc(len + 1);
	len--;
	if (!ms)
		return (0);
	while (len >= 0)
		ms[i++] = s[len--];
	ms[i] = 0;
	free (s);
	return (ms);
}

void	ft_ascii2bin(int n, int pid)
{
	char	*s;
	int		c;
	int		len;

	len = 8;
	s = (char *)malloc(len + 1);
	len = 0;
	while (len <= 7)
	{
		c = (n % 2) + 48;
		n /= 2;
		s[len] = c;
		len++;
	}
	s[len] = 0;
	s = ft_strrev(s, len);
	ft_send(s, pid);
	return ;
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (argv[1][i] && (argv[1][i] >= 48 && argv[1][i] <= 57))
				i++;
			else
				return (0);
		}
		i = 0;
		while (argv[2][i])
		{
			ft_ascii2bin(argv[2][i], ft_atoi(argv[1]));
			i++;
		}
	}
	return (0);
}
