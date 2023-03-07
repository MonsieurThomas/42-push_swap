/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:27:36 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 15:27:37 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	first_sort(t_list **stack_a, t_list **stack_b, int *move_count)
{
	int	i;

	i = 0;
	if (ft_isgood(*stack_a))
		return ;
	while (i < (*stack_a)->size)
	{
		if ((*stack_a)->number < ((*stack_a)->size) / 3)
		{
			swap_top_to_top(stack_a, stack_b, move_count);
			top_to_bottom(stack_b, move_count);
		}
		else if ((*stack_a)->number < ((*stack_a)->size) / 3 * 2)
			swap_top_to_top(stack_a, stack_b, move_count);
		else
			top_to_bottom(stack_a, move_count);
		i++;
	}
	i = (*stack_a)->size / 3 * 2;
}
