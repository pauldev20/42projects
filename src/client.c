/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:37:00 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/02 10:27:59 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send_byte(int pid, unsigned char c)
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

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
	{
		ft_printf("************USAGE************\n");
		ft_printf("*./client PID MESSAGE       *\n");
		ft_printf("*****************************\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (*argv[2])
		send_byte(pid, *argv[2]++);
	send_byte(pid, *argv[2]);
	return (0);
}
