/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:40:54 by fminardi          #+#    #+#             */
/*   Updated: 2021/05/26 15:40:55 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_last_command(t_stack *stack)
{
	while (stack->b_size > 0)
		repush(stack);
	while (min_in_stack(stack) > 0)
	{
		if (min_in_stack(stack) <= stack->a_size / 2)
		{
			rotate_a(stack);
			write(1, "ra\n", 3);
		}
		else
		{
			reverse_rotate_a(stack);
			write(1, "rra\n", 4);
		}
	}
	return ;
}

void	lis(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	stack->s_max_lis = 0;
	stack->lis = malloc(stack->a_size * sizeof(int));
	while (i < stack->a_size)
		stack->lis[i++] = 1;
	i = 0;
	while (j < stack->a_size)
	{
		i = j;
		while (i < stack->a_size)
		{
			if (stack->a[j] < stack->a[i] && stack->lis[j] == stack->lis[i])
			{
				stack->lis[i] += 1;
				if (stack->lis[i] > stack->s_max_lis)
					stack->s_max_lis = stack->lis[i];
			}
			i++;
		}
		j++;
	}
}

void	find_lis(t_stack *stack, int *lis_flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->a_size)
	{
		lis_flag[i] = 0;
		i++;
	}
	i = 0;
	while (stack->lis[i] != stack->s_max_lis)
		i++;
	while (i >= 0)
	{
		if (stack->lis[i] == (stack->s_max_lis - j))
		{
			lis_flag[i] = 1;
			j++;
		}
		i--;
	}
}

void	sequence(t_stack *stack, int *lis_flag, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (lis_flag[i] == 1)
		{
			rotate_a(stack);
			write(1, "ra\n", 3);
		}
		else
		{
			push_b(stack);
			write(1, "pb\n", 3);
		}
		i++;
	}
}

void	algorithm(t_stack *stack)
{
	int	i;
	int	size;
	int	*lis_flag;

	i = 0;
	size = stack->a_size;
	lis(stack);
	lis_flag = malloc(size * sizeof(int));
	find_lis(stack, lis_flag);
	free(stack->lis);
	sequence(stack, lis_flag, size);
	free(lis_flag);
	the_last_command(stack);
	return ;
}
