/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:08:07 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/03 14:35:02 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swapab(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	pushab(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (!*stack1)
		return ;
	tmp = *stack1;
	*stack1 = (*stack1)->next;
	tmp->next = *stack2;
	*stack2 = tmp;
}

void	rotateab(t_stack **stack)
{
	t_stack	*first;

	if (!*stack)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	while ((*stack)->next)
		stack = &((*stack)->next);
	first->next = NULL;
	(*stack)->next = first;
}

void	rev_rotateab(t_stack **stack)
{
	t_stack	*last;
	t_stack	*next_to_last;

	if (!*stack)
		return ;
	last = *stack;
	while (last->next)
	{
		if (!(last->next->next))
			next_to_last = last;
		last = last->next;
	}
	last->next = (*stack);
	next_to_last->next = NULL;
	*stack = last;
}
