/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:23:35 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 14:09:34 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	ft_mediane_2nd_part(t_list **stack, int number, int last_min)
{
	while ((*stack) != NULL)
	{
		if ((*stack)->content == last_min)
			(*stack)->number = number;
		*stack = (*stack)->next;
	}
	return (number);
}

void	ft_mediane(t_list **stack)
{
	t_list		*start;
	t_list		*min;
	signed long	last_min;
	int			number;

	start = *stack;
	number = 0;
	last_min = (long)INT_MIN -1;
	while (number < ft_lstsize(*stack))
	{
		min = ft_lstnew(INT_MAX, 0, 0);
		while ((*stack) != NULL)
		{
			if (min->content > (*stack)->content
				&& (*stack)->content > last_min)
				min->content = (*stack)->content;
			*stack = (*stack)->next;
		}
		last_min = min->content;
		*stack = start;
		number = ft_mediane_2nd_part(stack, number, last_min);
		number++;
		*stack = start;
		free(min);
	}
}
