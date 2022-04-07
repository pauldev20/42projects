/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:02:54 by pgeeser           #+#    #+#             */
/*   Updated: 2022/04/06 13:08:10 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = lst;
	if (!lst)
		return (0);
	while ((*ptr).next != NULL)
	{
		ptr = (*ptr).next;
		i++;
	}
	if (ptr->next == NULL)
		i++;
	return (i);
}
