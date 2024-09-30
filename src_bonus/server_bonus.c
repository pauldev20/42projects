/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:36:57 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/02 10:47:03 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

static t_char	g_msg_char;

static void	action(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_msg_char.sender = info->si_pid;
	g_msg_char.c |= ((sig == SIGUSR1) << g_msg_char.cur_pos--);
	if (g_msg_char.cur_pos == -1)
	{
		if (g_msg_char.c)
			ft_printf("%c", g_msg_char.c);
		else
			ft_printf("\n");
		kill(g_msg_char.sender, SIGUSR1);
		g_msg_char.cur_pos = 7;
		g_msg_char.c = 0;
		g_msg_char.sender = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("Server PID: %d\n", getpid());
	g_msg_char.c = 0;
	g_msg_char.sender = 0;
	g_msg_char.cur_pos = 7;
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = action;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
