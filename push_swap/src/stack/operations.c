/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:15:12 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/07 19:11:07 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
	ft_printf("s%c\n", stack->stackname);
}

void	push(t_stack *from, t_stack *to)
{
	int	tmp;

	tmp = from->array[0];
	remove_at_index(from, 0);
	add_at_index(to, 0, tmp);
	ft_printf("p%c\n", to->stackname);
}

void	rotate(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[0];
	remove_at_index(stack, 0);
	add_at_index(stack, stack->size, tmp);
	ft_printf("r%c\n", stack->stackname);
}

void	rev_rotate(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[stack->size - 1];
	remove_at_index(stack, stack->size - 1);
	add_at_index(stack, 0, tmp);
	ft_printf("rr%c\n", stack->stackname);
}
