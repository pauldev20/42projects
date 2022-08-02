/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:32:08 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/02 22:40:25 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char *argv[])
{
	t_list	*stacka;
	t_list	*stackb;
	int		i;

	stacka = NULL;
	stackb = NULL;
	i = 1;
	while (i++ < argc)
		ft_lstadd_back(&stacka, ft_lstnew(argv[i - 1]));
}
