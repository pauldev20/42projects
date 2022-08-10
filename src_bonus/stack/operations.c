/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:15:12 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/10 01:53:40 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
}

void	push(t_stack *from, t_stack *to)
{
	int	tmp;

	tmp = from->array[0];
	remove_at_index(from, 0);
	add_at_index(to, 0, tmp);
}

void	rotate(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[0];
	remove_at_index(stack, 0);
	add_at_index(stack, stack->size, tmp);
}

void	rev_rotate(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[stack->size - 1];
	remove_at_index(stack, stack->size - 1);
	add_at_index(stack, 0, tmp);
}
