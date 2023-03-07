/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_less_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:25:27 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 12:51:31 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	push_swap_less_4_2nd_part(int tmp2, int tmp3,
	int *move_count, t_list **stack_a)
{
	int	tmp1;

	tmp1 = (*stack_a)->number;
	if (tmp1 < tmp2 && tmp2 > tmp3 && tmp1 < tmp3)
	{
		top_to_bottom(stack_a, move_count);
		top_to_2nd(stack_a, move_count);
		bottom_to_top(stack_a, move_count);
	}
	else if (tmp1 > tmp2 && tmp2 > tmp3 && tmp1 > tmp3)
	{
		top_to_2nd(stack_a, move_count);
		bottom_to_top(stack_a, move_count);
	}
}

void	push_swap_less_4(t_list **stack_a, int *move_count)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;

	if (ft_isgood(*stack_a))
		return ;
	if ((*stack_a)->size == 3)
	{
		tmp1 = (*stack_a)->number;
		tmp2 = (*stack_a)->next->number;
		tmp3 = (*stack_a)->next->next->number;
		if (tmp1 < tmp2 && tmp2 > tmp3 && tmp1 > tmp3)
			bottom_to_top(stack_a, move_count);
		else if (tmp1 > tmp2 && tmp2 < tmp3 && tmp1 < tmp3)
			top_to_2nd(stack_a, move_count);
		else if (tmp1 > tmp2 && tmp2 < tmp3 && tmp1 > tmp3)
			top_to_bottom(stack_a, move_count);
		else
			push_swap_less_4_2nd_part(tmp2, tmp3, move_count, stack_a);
	}
	if ((*stack_a)->size == 2)
		top_to_2nd(stack_a, move_count);
}
