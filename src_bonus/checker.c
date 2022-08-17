/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:28:57 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/17 10:20:20 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(t_stack *stacka, t_stack *stackb)
{
	free_stack(stacka);
	free_stack(stackb);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(1);
}

void	parse_operations(t_stack *stacka, t_stack *stackb, char *opertation)
{
	if (!ft_strncmp(opertation, "sa", 2) || !ft_strncmp(opertation, "ss", 2))
		swap(stacka);
	else if (!ft_strncmp(opertation, "sb", 2)
		|| !ft_strncmp(opertation, "ss", 2))
		swap(stackb);
	else if (!ft_strncmp(opertation, "pa", 2))
		push(stackb, stacka);
	else if (!ft_strncmp(opertation, "pb", 2))
		push(stacka, stackb);
	else if (!ft_strncmp(opertation, "rra", 3)
		|| !ft_strncmp(opertation, "rrr", 3))
		rev_rotate(stacka);
	else if (!ft_strncmp(opertation, "rrb", 3)
		|| !ft_strncmp(opertation, "rrr", 3))
		rev_rotate(stackb);
	else if (!ft_strncmp(opertation, "ra", 2)
		|| !ft_strncmp(opertation, "rr", 2))
		rotate(stacka);
	else if (!ft_strncmp(opertation, "rb", 2)
		|| !ft_strncmp(opertation, "rr", 2))
		rotate(stackb);
	else
		error(stacka, stackb);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
		ft_printf("%d\n", stack->array[i++]);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	char	buff[10];
	int		read_bytes;

	if (argc < 2)
		return (0);
	stacka = get_stack(argc - 1, &argv[1], init_stack('a', 0));
	stackb = init_stack('b', stacka->size);
	index_stack(stacka);
	while (1)
	{
		read_bytes = read(STDIN_FILENO, buff, 10);
		buff[read_bytes] = '\0';
		if (!buff[0])
			break ;
		parse_operations(stacka, stackb, buff);
	}
	if (!stackb->size && stack_is_sorted(stacka))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(stacka);
	free_stack(stackb);
	return (0);
}
