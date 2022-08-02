/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:36:57 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/02 11:25:26 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static t_char	g_msg_char;

static void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_msg_char.c |= ((sig == SIGUSR1) << g_msg_char.cur_pos--);
	if (g_msg_char.cur_pos == -1)
	{
		if (g_msg_char.c)
			ft_printf("%c", g_msg_char.c);
		else
			ft_printf("\n");
		g_msg_char.cur_pos = 7;
		g_msg_char.c = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("Server PID: %d\n", getpid());
	g_msg_char.c = 0;
	g_msg_char.cur_pos = 7;
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
