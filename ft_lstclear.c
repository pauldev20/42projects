/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:29:38 by pgeeser           #+#    #+#             */
/*   Updated: 2022/04/08 12:35:48 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*ptr2;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr->next != NULL)
	{
		ptr2 = ptr;
		ft_lstdelone(ptr2, del);
		ptr = ptr2->next;
	}
	ft_lstdelone(ptr, del);
	*lst = NULL;
}
