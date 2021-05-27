/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repush_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:12:35 by fminardi          #+#    #+#             */
/*   Updated: 2021/05/26 16:12:36 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_rra(t_stack *stack, int i, int j)
{
	while (stack->b_size - i > 0)
	{
		reverse_rotate_both(stack);
		write(1, "rrr\n", 4);
		i++;
		j++;
	}
	while (stack->a_size - j > 0)
	{
		reverse_rotate_a(stack);
		write(1, "rra\n", 4);
		j++;
	}
}

void	rr_rb(t_stack *stack, int i, int j)
{
	while (j > 0)
	{
		rotate_both(stack);
		write(1, "rr\n", 3);
		j--;
		i--;
	}
	while (i > 0)
	{
		rotate_b(stack);
		write(1, "rb\n", 3);
		i--;
	}
}

void	rr_ra(t_stack *stack, int i, int j)
{
	while (i > 0)
	{
		rotate_both(stack);
		write(1, "rr\n", 3);
		j--;
		i--;
	}
	while (j > 0)
	{
		rotate_a(stack);
		write(1, "ra\n", 3);
		j--;
	}
}
