/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:46:45 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/09 23:54:26 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../../libft/libft.h"
# include "../../ft_printf/ft_printf.h"

typedef struct s_stack {
	char	stackname;
	int		*array;
	int		size;
}	t_stack;

// STACK
t_stack	*init_stack(char c, int size);
t_stack	*get_stack(int argc, char **argv, char c);
void	free_stack(t_stack *stack);

// OPERATIONS
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);

// STACK_HELPERS
void	position_to_top(t_stack *stack, int index);
int		find_next_smaller(t_stack *stack, int nb);
int		find_next_bigger(t_stack *stack, int nb);
void	remove_at_index(t_stack *stack, int index);
void	add_at_index(t_stack *stack, int index, int nb);

// OPERATIONS_BOTH
void	bothswap(t_stack *stack1, t_stack *stack2);
void	bothrotate(t_stack *stack1, t_stack *stack2);
void	bothrev_rotate(t_stack *stack1, t_stack *stack2);

// ADDITIONAL_STACK_HELPERS
void	index_stack(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
int		biggest_in_stack(t_stack *stack);
int		smallest_in_stack(t_stack *stack);

// ADDITIONAL_STACK_HELPERS_2
int		int_range_from_top(t_stack *stack, int min, int max);
int		int_range_from_bottom(t_stack *stack, int min, int max);

// VALIDATE
void	on_error(t_stack *stack);
int		validate(char *str, t_stack *stack);

#endif