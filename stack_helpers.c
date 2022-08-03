/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:48:58 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/03 16:21:39 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stack_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	stack_add(t_stack **stack, int val)
{
	t_stack	*new;

	if (!stack)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->value = val;
	new->next = NULL;
	if (!(*stack))
		(*stack) = new;
	else
	{
		while ((*stack)->next)
			stack = &((*stack)->next);
		(*stack)->next = new;
	}
}

void	stack_iter(t_stack *stack, void (*f)(int))
{
	if (!stack || !f)
		return ;
	while (stack)
	{
		f(stack->value);
		stack = stack->next;
	}
}

void	stack_clear(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		stack = &(*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

t_stack	*stack_at_index(t_stack **stack, int index)
{
	while (index--)
		stack = &(*stack)->next;
	return (*stack);
}
