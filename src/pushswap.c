/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:32:08 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/09 23:13:56 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = get_stack(argc - 1, &argv[1], 'a');
	stackb = init_stack('b', stacka->size);
	index_stack(stacka);
	if (stacka->size < 6)
		sort_small(stacka, stackb);
	else if (stacka->size <= 500)
		sort_big(stacka, stackb);
	free_stack(stacka);
	free_stack(stackb);
	return (0);
}
