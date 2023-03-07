/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_less_6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:14:05 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 15:26:00 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	push_swap_less_6_2nd_part(t_list **stack_a, int max, int *move_count)
{
	int		min;
	int		max2;
	t_list	*start;

	if ((*stack_a)->content == max)
	{
		top_to_bottom(stack_a, move_count);
		return ;
	}
	start = *stack_a;
	min = (*stack_a)->content;
	max2 = (*stack_a)->content;
	while ((*stack_a)->content != max)
	{
		if ((*stack_a)->content < min)
			min = (*stack_a)->content;
		if ((*stack_a)->content > max)
			max = (*stack_a)->content;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = start;
	push_swap_less_6_4th_part(stack_a, max, min, move_count);
}

void	push_swap_less_6_4th_part(t_list **stack_a, int max,
		int min, int *move_count)
{
	if ((*stack_a)->content == min)
		top_to_bottom(stack_a, move_count);
	else if ((*stack_a)->next->content == min)
	{
		top_to_2nd(stack_a, move_count);
		top_to_bottom(stack_a, move_count);
	}
	else
	{
		top_to_bottom(stack_a, move_count);
		top_to_2nd(stack_a, move_count);
		bottom_to_top(stack_a, move_count);
		top_to_2nd(stack_a, move_count);
		top_to_bottom(stack_a, move_count);
	}
	push_swap_less_6_2nd_part(stack_a, max, move_count);
}

void	push_swap_less_6_3rd_part(t_list **stack_a, int *move_count,
	int min, int max)
{
	t_list	*start;

	start = *stack_a;
	while ((*stack_a)->content != min)
		top_to_bottom(stack_a, move_count);
	if (ft_isgood(*stack_a))
		return ;
	start = *stack_a;
	while ((*stack_a)->next != NULL)
		(*stack_a) = (*stack_a)->next;
	while ((*stack_a)->content != max)
	{
		*stack_a = start;
		top_to_2nd(stack_a, move_count);
		top_to_bottom(stack_a, move_count);
		while ((*stack_a)->next != NULL)
			(*stack_a) = (*stack_a)->next;
	}
	*stack_a = start;
	if (ft_isgood(*stack_a))
		return ;
	top_to_bottom(stack_a, move_count);
	push_swap_less_6_2nd_part(stack_a, max, move_count);
}

void	push_swap_less_6(t_list **stack_a, int *move_count)
{
	int		min;
	int		max;
	t_list	*start;

	if (ft_isgood(*stack_a))
		return ;
	start = *stack_a;
	min = (*stack_a)->content;
	max = (*stack_a)->content;
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->content < min)
			min = (*stack_a)->content;
		if ((*stack_a)->content > max)
			max = (*stack_a)->content;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = start;
	push_swap_less_6_3rd_part(stack_a, move_count, min, max);
}
