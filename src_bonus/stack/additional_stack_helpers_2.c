/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_stack_helpers_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:13:07 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/09 23:14:33 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	int_range_from_top(t_stack *stack, int min, int max)
{
	int	i;

	i = 0;
	while (i++ < stack->size)
		if (stack->array[i - 1] >= min && stack->array[i - 1] <= max)
			return (i - 1);
	return (-1);
}

int	int_range_from_bottom(t_stack *stack, int min, int max)
{
	int	i;

	i = stack->size - 1;
	while (i-- >= 0)
		if (stack->array[i + 1] >= min && stack->array[i + 1] <= max)
			return (i + 1);
	return (-1);
}
