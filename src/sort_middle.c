/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:05:22 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 15:05:23 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	go_up_loop(t_list **stack, int max, int *move_count)
{
	if ((*stack)->number == max)
		return ;
	while ((*stack)->number != max)
	{
		top_to_bottom(stack, move_count);
	}
}

void	go_down_loop(t_list **stack, int max, int *move_count)
{
	if ((*stack)->next == NULL)
		return ;
	while (ft_lstlast(*stack)->number != max)
	{
		bottom_to_top(stack, move_count);
	}
}

void	sort_middle(t_list **stack_a, t_list **stack_b, int *move_count)
{
	while ((*stack_b)->number >= ((*stack_b)->size) / 3)
	{
		if ((*stack_b)->number >= ((*stack_b)->size) / 2)
			swap_top_to_top(stack_b, stack_a, move_count);
		else
		{
			swap_top_to_top(stack_b, stack_a, move_count);
			top_to_bottom(stack_a, move_count);
		}
	}
	sort_biggest(stack_a, stack_b, move_count);
}
