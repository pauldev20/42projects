/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:37:00 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/02 11:34:30 by pgeeser          ###   ########.fr       */
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

void	help_text(void)
{
	ft_printf("************USAGE************\n");
	ft_printf("*./client PID MESSAGE       *\n");
	ft_printf("*PID: needs to be a number  *\n");
	ft_printf("*     bigger than 0         *\n");
	ft_printf("*MESSAGE: string of chars   *\n");
	ft_printf("*****************************\n");
}

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc == 3 && ft_atoi(argv[1]) > 0)
	{
		pid = ft_atoi(argv[1]);
		while (*argv[2])
			send_byte(pid, *argv[2]++);
		send_byte(pid, *argv[2]);
		return (0);
	}
	help_text();
	return (1);
}
