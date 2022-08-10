/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:43:54 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/10 01:14:50 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3_stack(t_stack *stack)
{
	int	*array;

	array = stack->array;
	if (array[0] > array[1] && array[1] < array[2] && array[2] < array[0])
		rotate(stack);
	if (array[0] < array[1] && array[1] > array[2] && array[2] < array[0])
		rev_rotate(stack);
	if (array[0] > array[1] && array[1] < array[2] && array[2] > array[0])
		swap(stack);
	if (array[0] > array[1] && array[1] > array[2] && array[2] < array[0])
	{
		swap(stack);
		rev_rotate(stack);
	}
	if (array[0] < array[1] && array[1] > array[2] && array[2] > array[0])
	{
		swap(stack);
		rotate(stack);
	}
}

void	sort_5_stack(t_stack *stmain, t_stack *sttmp)
{
	int	index;
	int	i;

	push(stmain, sttmp);
	push(stmain, sttmp);
	sort_3_stack(stmain);
	i = 0;
	while (sttmp->array && i < sttmp->size)
	{
		index = find_next_bigger(stmain, sttmp->array[i]);
		if (index > -1)
			position_to_top(stmain, index);
		else
			position_to_top(stmain, find_next_bigger(stmain, -1));
		push(sttmp, stmain);
	}
	position_to_top(stmain, find_next_bigger(stmain, -1));
}

void	sort_small(t_stack *stmain, t_stack *sttmp)
{
	if (stmain->size == 2 && !stack_is_sorted(stmain))
		swap(stmain);
	if (stmain->size == 3)
		sort_3_stack(stmain);
	if (stmain->size == 5)
		sort_5_stack(stmain, sttmp);
}
