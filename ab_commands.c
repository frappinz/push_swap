/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:03:59 by fminardi          #+#    #+#             */
/*   Updated: 2021/05/26 14:04:00 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both(t_stack *stack)
{
	reverse_rotate_b(stack);
	reverse_rotate_a(stack);
}

void	rotate_both(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

void	swap_both(t_stack *stack)
{
	swap_b(stack);
	swap_a(stack);
}
