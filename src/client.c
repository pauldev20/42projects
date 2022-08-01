/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:37:00 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/01 17:55:45 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_byte(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c & 0b10000000)
			kill((pid_t)pid, SIGUSR1);
		else
			kill((pid_t)pid, SIGUSR2);
		c <<= 1;
		usleep(100);
	}
}

void	help_text(void)
{
	ft_printf("************USAGE************\n");
	ft_printf("*./client PID MESSAGE       *\n");
	ft_printf("*****************************\n");
}

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (*argv[2])
			send_byte(pid, *argv[2]++);
		send_byte(pid, *argv[2]);
	}
	else
	{
		help_text();
		return (1);
	}
	return (0);
}
