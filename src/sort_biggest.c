/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:26:19 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 14:59:53 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	what_is_max(t_list **stack_a)
{
	t_list	*start;
	int		max;

	start = *stack_a;
	max = (*stack_a)->number;
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->number > max)
			max = (*stack_a)->number;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = start;
	return (max);
}

void	sort_biggest_3rd_part(t_list **stack_a, int *move_count,
	int max, int *debut)
{
	int		fin;
	t_list	*start;

	fin = ft_lstsize(*stack_a);
	start = *stack_a;
	while ((*stack_a) != NULL)
	{
		(*debut) += 2;
		if ((*stack_a)->number == max)
		{
			if ((*debut) < fin)
			{
				*stack_a = start;
				go_up_loop(stack_a, max, move_count);
				break ;
			}
			else
			{
				*stack_a = start;
				go_down_loop(stack_a, max, move_count);
				break ;
			}
		}
		*stack_a = (*stack_a)->next;
	}
}

void	sort_biggest_2nd_part(int debut, t_list **stack_a, t_list **stack_b,
	int *move_count)
{
	int	fin;

	fin = ft_lstsize(*stack_a);
	if (debut < fin)
	{
		swap_top_to_top(stack_a, stack_b, move_count);
		top_to_bottom(stack_b, move_count);
	}
	else
	{
		bottom_to_top(stack_a, move_count);
		swap_top_to_top(stack_a, stack_b, move_count);
		top_to_bottom(stack_b, move_count);
	}
}

void	sort_biggest(t_list **stack_a, t_list **stack_b, int *move_count)
{
	t_list	*start;
	int		max;
	int		debut;
	int		fin;
	int		rotate_number;

	if (ft_isgood(*stack_a))
		return ;
	rotate_number = ft_lstsize(*stack_a) + 1;
	while (--rotate_number > 0)
	{
		debut = 0;
		fin = ft_lstsize(*stack_a);
		start = *stack_a;
		max = what_is_max(stack_a);
		sort_biggest_3rd_part(stack_a, move_count, max, &debut);
		sort_biggest_2nd_part(debut, stack_a, stack_b, move_count);
	}
}
