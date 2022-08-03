/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:32:27 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/03 16:21:48 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_stack {
	int				value;
	struct s_stack	*next;
}	t_stack;

void	stack_add(t_stack **stack, int val);
void	stack_iter(t_stack *stack, void (*f)(int));
void	stack_clear(t_stack **stack);
int		stack_is_sorted(t_stack *stack);
t_stack	*stack_at_index(t_stack **stack, int index);

void	swapab(t_stack **stack);
void	pushab(t_stack **stack1, t_stack **stack2);
void	rotateab(t_stack **stack);
void	rev_rotateab(t_stack **stack);

void	bothswap(t_stack **stack1, t_stack **stack2);
void	bothrotate(t_stack **stack1, t_stack **stack2);
void	bothrev_rotate(t_stack **stack1, t_stack **stack2);

#endif