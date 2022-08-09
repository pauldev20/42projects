/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:32:27 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/08 15:54:01 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./../libft/libft.h"
# include "./../ft_printf/ft_printf.h"
# include "./stack/stack.h"

void	print_stack(t_stack *stack);

// SMALL_STACK
void	sort_3_stack(t_stack *stack);
void	sort_5_stack(t_stack *stmain, t_stack *sttmp);
void	sort_small(t_stack *stmain, t_stack *sttmp);

// BIG_STACK
void	chunk_sorting(t_stack *sta, t_stack *stb, int chunksize);
void	sort_big(t_stack *sta, t_stack *stb);

#endif