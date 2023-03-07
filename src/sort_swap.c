/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:06:47 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 15:06:48 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	swap_top_to_top(t_list **stack1, t_list **stack2, int *move_count)
{
	t_list	*tmp;

	tmp = *stack1;
	if (tmp->name == 'a')
		tmp->name = 'b';
	else
		tmp->name = 'a';
	*stack1 = (*stack1)->next;
	ft_lstadd_front(stack2, tmp);
	ft_putstr("p");
	ft_putchar((tmp)->name);
	ft_putstr("\n");
	(*move_count)++;
}
