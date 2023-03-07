/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:06:00 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 15:06:01 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	final_move(t_list **stack_a, t_list **stack_b, int *move_count)
{
	while (*stack_b != NULL)
	{
		swap_top_to_top(stack_b, stack_a, move_count);
	}
}

void	sort_smallest(t_list **stack_a, t_list **stack_b, int *move_count)
{
	while ((*stack_b)->number != (*stack_b)->size - 1)
	{
		if ((*stack_b)->number <= ((*stack_b)->size) / 6)
		{
			swap_top_to_top(stack_b, stack_a, move_count);
			top_to_bottom(stack_a, move_count);
		}
		else
			swap_top_to_top(stack_b, stack_a, move_count);
	}
	sort_biggest(stack_a, stack_b, move_count);
}
