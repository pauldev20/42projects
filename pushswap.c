/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:32:08 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/03 16:58:03 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_sm_5(t_stack **sta, t_stack **stb)
{
	while (!stack_is_sorted(*sta))
	{
		pushab(sta, stb);
		pushab(sta, stb);
		if ((*sta)->value > (*sta)->next->value)
			bothrotate(sta, stb);
		pushab(stb, sta);
		pushab(stb, sta);
	}
}

void	iter(int val)
{
	ft_printf("%d\n", val);
}

int	main(int argc, char *argv[])
{
	t_stack	*stacka;
	t_stack	*stackb;
	int		i;

	stacka = NULL;
	stackb = NULL;
	i = 1;
	while (i++ < argc)
		stack_add(&stacka, ft_atoi(argv[i - 1]));
	sort_sm_5(&stacka, &stackb);
	ft_printf("Stack A:\n");
	stack_iter(stacka, iter);
	ft_printf("Stack B:\n");
	stack_iter(stackb, iter);
	return (0);
}
