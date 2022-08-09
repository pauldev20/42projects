/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_stack_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:44:24 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/08 14:30:07 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	index_stack(t_stack *stack)
{
	int	i;
	int	index;
	int	last;
	int	*array;

	last = -2147483648;
	array = ft_calloc(stack->size, sizeof(int));
	i = 0;
	while (i < stack->size)
	{
		index = find_next_bigger(stack, last);
		last = stack->array[index];
		array[index] = i;
		i++;
	}
	free(stack->array);
	stack->array = array;
}

int	stack_is_sorted(t_stack *stack)
{
	int	i;
	int	nb;

	i = 0;
	nb = -2147483648;
	while (i < stack->size)
	{
		if (stack->array[i] > nb)
			nb = stack->array[i];
		else
			return (0);
		i++;
	}
	return (1);
}

int	biggest_in_stack(t_stack *stack)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = -2147483648;
	while (i < stack->size)
	{
		if (stack->array[i] > biggest)
			biggest = stack->array[i];
		i++;
	}
	return (biggest);
}

int	smallest_in_stack(t_stack *stack)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = 2147483647;
	while (i < stack->size)
	{
		if (stack->array[i] < smallest)
			smallest = stack->array[i];
		i++;
	}
	return (smallest);
}
