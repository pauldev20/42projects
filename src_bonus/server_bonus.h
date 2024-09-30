/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:39:17 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/02 10:46:49 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <unistd.h>
# include <signal.h>
# include "./../ft_printf/ft_printf.h"

typedef struct s_char {
	pid_t			sender;
	unsigned char	c;
	int				cur_pos;
}	t_char;

#endif