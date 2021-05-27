/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:41:21 by fminardi          #+#    #+#             */
/*   Updated: 2021/05/26 15:41:22 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	right_spot(t_stack *stack, int i)
{
	int	j;

	j = 0;
	if (bigger_than_stack_a(stack, i))
		return (max_in_stack(stack) + 1);
	if (smaller_than_stack_a(stack, i))
		return (min_in_stack(stack));
	while (j < stack->a_size)
	{
		if (stack->b[i] > stack->a[j] && stack->b[i] < stack->a[j + 1])
			return (j + 1);
		j++;
	}
	return (0);
}

int	combination(t_stack *stack, int i)
{
	while (i < stack->b_size)
	{
		if (right_spot(stack, i) < stack->a_size / 2)
		{
			if (i <= stack->b_size / 2)
				return (1);
			return (2);
		}
		else
		{
			if (i < stack->b_size / 2)
				return (3);
			return (4);
		}
	}
	return (0);
}

int	count_moves(t_stack *stack, int i, int j)
{
	int	count;

	if (combination(stack, i) == 1)
	{
		if (j > i)
			count = j;
		else
			count = i;
	}
	else if (combination(stack, i) == 2)
		count = j + (stack->b_size - i);
	else if (combination (stack, i) == 3)
		count = stack->a_size - j + i - 1;
	else
	{
		if ((stack->a_size - j) > (stack->b_size - i))
			count = stack->a_size - j;
		else
			count = stack->b_size - i;
	}
	return (count);
}

int	right_nb(t_stack *stack)
{
	int	i;
	int	index;
	int	count;
	int	count2;
	int	j;

	i = 0;
	index = 0;
	count2 = 32000;
	while (i < stack->b_size)
	{
		j = right_spot(stack, i);
		count = count_moves(stack, i, j);
		if (count < count2)
		{
			count2 = count;
			index = i;
		}
		i++;
	}
	return (index);
}

void	repush(t_stack *stack)
{
	int	i;
	int	j;

	i = right_nb(stack);
	j = right_spot(stack, i);
	if (combination(stack, i) == 1)
	{
		if (i <= j)
			rr_ra(stack, i, j);
		else
			rr_rb(stack, i, j);
	}
	else if (combination(stack, i) == 4)
	{
		if ((stack->b_size - i) < (stack->a_size - j))
			rrr_rra(stack, i, j);
		else
			rrr_rrb(stack, i, j);
	}
	else if (combination(stack, i) == 2)
		ra_rrb(stack, i, j);
	else
		rra_rb(stack, i, j);
	push_a(stack);
	write(1, "pa\n", 3);
}
