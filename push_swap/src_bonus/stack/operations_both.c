/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:24:03 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/10 01:53:29 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	bothswap(t_stack *stack1, t_stack *stack2)
{
	int	tmp;

	tmp = stack1->array[0];
	stack1->array[0] = stack1->array[1];
	stack1->array[1] = tmp;
	tmp = stack2->array[0];
	stack2->array[0] = stack2->array[1];
	stack2->array[1] = tmp;
}

void	bothrotate(t_stack *stack1, t_stack *stack2)
{
	int	tmp;

	tmp = stack1->array[0];
	remove_at_index(stack1, 0);
	add_at_index(stack1, stack1->size, tmp);
	tmp = stack2->array[0];
	remove_at_index(stack2, 0);
	add_at_index(stack2, stack2->size, tmp);
}

void	bothrev_rotate(t_stack *stack1, t_stack *stack2)
{
	int	tmp;

	tmp = stack1->array[stack1->size - 1];
	remove_at_index(stack1, stack1->size - 1);
	add_at_index(stack1, 0, tmp);
	tmp = stack2->array[stack2->size - 1];
	remove_at_index(stack2, stack2->size - 1);
	add_at_index(stack2, 0, tmp);
}
