/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:36:39 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/03 14:38:50 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	bothswap(t_stack **stack1, t_stack **stack2)
{
	swapab(stack1);
	swapab(stack2);
}

void	bothrotate(t_stack **stack1, t_stack **stack2)
{
	rotateab(stack1);
	rotateab(stack2);
}

void	bothrev_rotate(t_stack **stack1, t_stack **stack2)
{
	rev_rotateab(stack1);
	rev_rotateab(stack2);
}
