/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:42:22 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/17 11:12:23 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	position_to_top(t_stack *stack, int index)
{
	if (index == 0 || index == -1)
		return ;
	if (index <= stack->size / 2)
	{
		while (index-- && stack->size)
			rotate(stack);
		return ;
	}
	while (stack->size - (index++) && stack->size)
		rev_rotate(stack);
}

int	find_next_smaller(t_stack *stack, long long nb)
{
	int	next_smallest;
	int	moves;
	int	i;

	i = 0;
	moves = -1;
	next_smallest = smallest_in_stack(stack);
	while (i < stack->size)
	{
		if (stack->array[i] < nb && stack->array[i] >= next_smallest)
		{
			next_smallest = stack->array[i];
			moves = i;
		}
		i++;
	}
	return (moves);
}

int	find_next_bigger(t_stack *stack, long long nb)
{
	int	next_biggest;
	int	moves;
	int	i;

	i = 0;
	moves = -1;
	next_biggest = biggest_in_stack(stack);
	while (i < stack->size)
	{
		if (stack->array[i] > nb && stack->array[i] <= next_biggest)
		{
			next_biggest = stack->array[i];
			moves = i;
		}
		i++;
	}
	return (moves);
}

void	remove_at_index(t_stack *stack, int index)
{
	int	i;
	int	j;

	if (stack->size)
	{
		if (stack->size - 1 > 0)
		{
			i = 0;
			while (i < index && i < stack->size - 1)
				i++;
			i--;
			j = 0;
			while (i + j++ < stack->size - 1)
				stack->array[i + j] = stack->array[i + j + 1];
			stack->array[i + j] = 0;
			stack->size -= 1;
			return ;
		}
		stack->array[0] = 0;
		stack->size = 0;
	}
}

void	add_at_index(t_stack *stack, int index, int nb)
{
	int	i;

	i = 0;
	if (stack->size)
	{
		if (index > stack->size)
			index = stack->size;
		i = stack->size;
		while (i >= index)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->size += 1;
		stack->array[index] = nb;
		return ;
	}
	stack->array[i] = nb;
	stack->size += 1;
}
