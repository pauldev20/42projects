/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:54:42 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/09 23:54:57 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	add_to_stack(t_stack **stack, int nb)
{
	int	*array;
	int	i;

	array = (*stack)->array;
	(*stack)->array = (int *)malloc(sizeof(int) * ((*stack)->size + 1));
	i = 0;
	if (array)
	{
		while (i++ < (*stack)->size)
			(*stack)->array[i - 1] = array[i - 1];
		i--;
		free(array);
	}
	(*stack)->array[i] = nb;
	(*stack)->size += 1;
}

t_stack	*init_stack(char c, int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!size)
		stack->array = NULL;
	else
		stack->array = (int *)ft_calloc(size, sizeof(int));
	stack->size = 0;
	stack->stackname = c;
	return (stack);
}

void	free_split_array(char **array)
{
	int	i;

	i = 0;
	while (array[i++])
		free(array[i - 1]);
	free(array);
}

t_stack	*get_stack(int argc, char **argv, char c)
{
	int		i;
	int		j;
	t_stack	*stack;
	char	**array;
	int		error;

	error = 0;
	stack = init_stack(c, 0);
	i = 0;
	while (i++ < argc && !error)
	{
		array = ft_split(argv[i - 1], ' ');
		j = 0;
		while (array[j++] && !error)
		{
			if (!validate(array[j - 1], stack))
				error = 1;
			add_to_stack(&stack, ft_atoi(array[j - 1]));
		}
	}
	if (error)
		on_error(stack);
	free_split_array(array);
	return (stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}
