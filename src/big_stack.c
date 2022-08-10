/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:51:21 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/10 01:19:55 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	move_chunk(t_stack *sta, t_stack *stb, int min, int max)
{
	int	i;
	int	index[2];

	i = max - min + 1;
	while (i-- > 0)
	{
		index[0] = int_range_from_top(sta, min, max);
		index[1] = int_range_from_bottom(sta, min, max);
		if (index[0] < sta->size - index[1])
			position_to_top(sta, index[0]);
		else
			position_to_top(sta, index[1]);
		push(sta, stb);
	}
}

void	sort_chunk(t_stack *sta, t_stack *stb)
{
	int	index[2];

	while (stb->size > 0)
	{
		index[0] = find_next_bigger(stb, smallest_in_stack(stb) - 1);
		index[1] = find_next_smaller(stb, biggest_in_stack(stb) + 1);
		if (index[0] < index[1])
		{
			if (index[0] > 0)
				position_to_top(stb, index[0]);
			position_to_top(sta, find_next_bigger(sta, stb->array[0]));
			push(stb, sta);
			rotate(sta);
		}
		else
		{
			if (index[1] > 0)
				position_to_top(stb, index[1]);
			position_to_top(sta, find_next_bigger(sta, stb->array[0]));
			push(stb, sta);
		}
	}
}

void	chunk_sorting(t_stack *sta, t_stack *stb, int chunksize)
{
	int	chunks;
	int	min;
	int	max;

	chunks = sta->size / chunksize;
	max = sta->size - 1;
	while (chunks)
	{
		if (chunks == 1)
			min = smallest_in_stack(sta);
		else
			min = (chunks * chunksize) - chunksize;
		move_chunk(sta, stb, min, max);
		sort_chunk(sta, stb);
		max = min - 1;
		chunks--;
	}
	position_to_top(sta, find_next_bigger(sta, smallest_in_stack(sta) - 1));
}

void	sort_big(t_stack *sta, t_stack *stb)
{
	if (sta->size <= 100)
		chunk_sorting(sta, stb, sta->size / 4);
	else if (sta->size <= 500)
		chunk_sorting(sta, stb, sta->size / 8);
	else
		chunk_sorting(sta, stb, sta->size / 12);
}
