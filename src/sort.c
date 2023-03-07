/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:08:03 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 15:10:47 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	bottom_to_top(t_list **stack, int *move_count)
{
	t_list	*tmp;
	t_list	*start;

	start = *stack;
	if ((*stack)->next != NULL)
	{
		while ((*stack) != NULL)
		{
			if ((*stack)->next->next == NULL)
			{
				tmp = (*stack)->next;
				(*stack)->next = NULL;
			}
			*stack = (*stack)->next;
		}
		*stack = start;
		ft_lstadd_front(stack, tmp);
		ft_putstr("rr");
		ft_putchar(tmp->name);
		ft_putchar('\n');
		(*move_count) += 1;
	}
}

void	top_to_bottom(t_list **stack, int *move_count)
{
	t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		ft_lstadd_back(stack, tmp);
		ft_putchar('r');
		ft_putchar(tmp->name);
		ft_putchar('\n');
		(*move_count)++;
	}
}

void	top_to_2nd(t_list **stack, int *move_count)
{
	t_list	*tmp;

	tmp = NULL;
	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		(*stack) = tmp;
	}
	ft_putchar('s');
	ft_putchar(tmp->name);
	ft_putchar('\n');
	(*move_count)++;
}
