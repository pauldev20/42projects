/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:27:42 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/17 10:53:12 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	is_int(char *str)
{
	int	first;
	int	digit;

	first = 1;
	digit = 0;
	while (*str)
	{
		if ((*str == '-' || *str == '+' ) && first)
			first = 0;
		else if (!ft_isdigit(*str))
			return (0);
		else
		{
			first = 0;
			digit++;
		}
		str++;
	}
	if (*str == '\0' && !first && !digit)
		return (0);
	return (1);
}

static int	allready_in_stack(char *str, t_stack *stack)
{
	int	nb;
	int	i;

	i = 0;
	nb = ft_atoi(str);
	while (i++ < stack->size)
		if (stack->array[i - 1] == nb)
			return (1);
	return (0);
}

static int	nb_bigger_int(char *str)
{
	int	nb;
	int	neg;

	nb = 0;
	neg = -1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			neg = 1;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 - (*str++ - '0');
		if (nb > 0 || (nb == -2147483648 && neg < 0))
			return (1);
	}
	return (0);
}

void	on_error(t_stack *stack)
{
	if (stack->array)
		free(stack->array);
	free(stack);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(1);
}

int	validate(char *str, t_stack *stack)
{
	if (!is_int(str))
		return (0);
	if (nb_bigger_int(str))
		return (0);
	if (allready_in_stack(str, stack))
		return (0);
	return (1);
}
